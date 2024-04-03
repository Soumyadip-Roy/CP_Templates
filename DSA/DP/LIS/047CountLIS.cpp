#include <bits/stdc++.h>
using namespace std;

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

        vector<int> dp(n,1);
        vector<int> ct(n,1);

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for ( int previ = 0; previ < i; previ++)
            {
                if(v[i]>v[previ]){
                    dp[i] = max(dp[i],1+dp[previ]);
                    //inherit
                    ct[i] = ct[previ];
                }
                else if(v[i]>v[previ] and dp[i] + 1 == dp[previ]){
                    //increase if count is same
                    ct[i] += ct[previ];
                }
                mx = max(mx,dp[i]); 
            }
        }
        cout<<mx;
        int nos = 0;

        for (int i = 0; i < n; i++)
        {
            if(dp[i]==mx){
                nos+=ct[i];
            }
        }

        cout<<nos;
        
    }
}
