#include <bits/stdc++.h>
using namespace std;

template <class T>
void coutfs(T x)
{
    for (auto i : x)
    {
        cout << i.first << " " << i.second << endl;
    }
}
template <class T>
void coutele(T x)
{
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << endl;
}

const int m = 1e9;

int f(int i, int j, int isTrue, string &v, vector<int> v)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue == 1)
            return v[i] == 'T' ? 1 : 0;
        else
            return v[i] == 'F' ? 1 : 0;
    }
    int ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lT = f(i, ind - 1, 1, v);
        int lF = f(i, ind - 1, 0, v);
        int rT = f(ind + 1, j, 1, v);
        int rF = f(ind + 1, j, 0, v);

        // Check the operator at the current index and update ways accordingly.
        if (v[ind] == '&')
        {
            if (isTrue)
                ways = ways + (lT * rT);
            else
                ways = ways + (lF * rT) + (lT * rF) + (lF * rF);
        }
        else if (v[ind] == '|')
        {
            if (isTrue)
                ways = ways + (lF * rT) + (lT * rF) + (lT * rT);
            else
                ways = ways + (lF * rF);
        }
        else
        { // XOR operator
            if (isTrue)
                ways = ways + (lF * rT) + (lT * rF);
            else
                ways = ways + (lF * rF) + (lT * rT);
        }
    }
    return ways;
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
        string v;
        cin >> v;

        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        cout << f(0, n - 1, 1, v) << endl;
    }
}
