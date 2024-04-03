#include <bits/stdc++.h>
using namespace std;

int f(int i, int previ, int n, vector<int> v, vector<vector<int>> dp)
{
    if (i == n)
    {
        return 0;
    }

    if (dp[i][previ + 1] != -1)
    {
        return dp[i][previ + 1];
    }
    int take = 0;
    if (previ == -1 or v[i] > v[previ])
        take = 1 + f(i + 1, i, n, v, dp);

    int notTake = 0 + f(i + 1, previ, n, v, dp);

    return dp[i][previ + 1] = max(take, notTake);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // cout<<f(0,-1,n,v,dp);

        // dont write base case specifiaclly

        // do coordinate shift for the 2nd parameter(ie prev index) int the 2d dp array

        // sc = o(n^2)
        // tc = o(n^2)
        for (int i = n - 1; i >= 0; i--)
        {
            for (int previ = i - 1; previ >= -1; previ--)
            {
                int take = 0;
                if (previ == -1 or v[i] > v[previ])
                    take = 1 + dp[i + 1][i + 1];

                int notTake = 0 + dp[i + 1][previ + 1];

                dp[i][previ + 1] = max(take, notTake);
            }
        }
        cout << dp[0][0];


        // space optimization 
        // sc = o(n) * 2
        // tc = o(n*n)
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int previ = i - 1; previ >= -1; previ--)
            {
                int take = 0;
                if (previ == -1 or v[i] > v[previ])
                    take = 1 + next[i + 1];

                int notTake = 0 + curr[previ +  1];

                curr[previ + 1] = max(take, notTake);
            }
            next = curr;
        }
        cout << next[0];
    }
}
