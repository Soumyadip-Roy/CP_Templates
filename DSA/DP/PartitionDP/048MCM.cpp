#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> v,  vector<vector<int>> &dp){
    if(i==j) return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn = 1e9;

    for(int k = i; k<=j-1; k++){
        int steps = v[i-1]*v[k]*v[j] + f(i,k,v,dp) + f(k+1,j,v,dp);
        mn = min(steps,mn);
    }

    return dp[i][j] = mn;
}

signed main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif

    
    int T = 1;cin >> T;
    while (T--)
    {
        int n;cin>>n;

        vector<int> v(n+1);
        for (int i = 0; i <= n; i++)
        {
            cin>>v[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        // return f(1,n,v,dp);
        

        //tabulation 

        //base case
        for (int i = 0; i <= n; i++)
        {
            dp[i][i] = 0;
        }

        for (int i = n; i>= 1; i--)
        {
            for (int j = i+1; j <= n; j++) //why j = i+1
            {
                int mn = 1e9;
                for(int k = i; k<= j-1; k++){
                    int steps = v[i-1]*v[k]*v[j] + dp[i][k] + dp[k+1][j];
                    mn = min(steps,mn);
                }
                dp[i][j] = mn;
            }
        }
        cout<<dp[1][n];
    }
}
