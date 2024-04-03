#include <bits/stdc++.h>
using namespace std;

long f(int i,int j,long *p, int n, vector<vector<long>> &dp){

    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(j){
        return dp[i][j] = max(-p[i]+f(i+1,0,p,n,dp),f(i+1,1,p,n,dp));
    }
    else{
        return dp[i][j] = max(p[i]+f(i+1,1,p,n,dp),f(i+1,0,p,n,dp));
    }
}


signed main()

{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;cin >> T;
    while (T--)
    {
        int n;cin>>n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin>>p[i];
        }

        vector<vector<int>> dp(n+2,vector<int> (2,0));
        
        // cout<<f(0,1,v,n,dp);

        dp[n][0]=0;
        dp[n][1]=0;

        for (int i = n-1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                long profit = 0;
                if(j){
                    profit = max(-p[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit = max(p[i]+dp[i+2][1],dp[i+1][0]);
                }

                dp[i][j] = profit;
            }
        }
    
        // cout<<dp[0][1];

        for (int i = 0; i < n; i++)
        {
            cout<<dp[i][0]<<" ";
            cout<<dp[i][1]<<endl;
        }
    }
}
