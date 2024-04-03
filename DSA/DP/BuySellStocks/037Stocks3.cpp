#include <bits/stdc++.h>
using namespace std;

long f(int i,int j,int cap, vector<int> p, int n, vector<vector<vector<int>>> &dp){
    
    if(i==n or cap==0){
        return 0;
    }
    if(dp[i][j][cap]!=-1){
        return dp[i][j][cap];
    }
    
    if(j){
        return dp[i][j][cap] = max(-p[i]+f(i+1,0,cap,p,n,dp),f(i+1,1,cap,p,n,dp));
    }
    else{
        return dp[i][j][cap] = max(p[i]+f(i+1,1,cap-1,p,n,dp),f(i+1,0,cap,p,n,dp));
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

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));
        
        // cout<<f(0,1,2,p,n,dp);


        for (int i = 0; i < 3; i++)
        {
            dp[n][0][i]=0;
            dp[n][1][i]=0;
        }
        
        for (int i = 0; i < n; i++)
        {
            dp[i][0][0]=0;
            dp[i][1][0]=0;
        }
        
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for(int cap = 1;cap<=2;cap++){
                    long profit = 0;
                    if(j){
                        profit = max(-p[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else{
                        profit = max(p[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                    dp[i][j][cap] = profit;
                }              
            }
        }

        cout<<dp[0][1][2];

        vector<vector<int>> a(n+1,vector<int> (5,0));
        // Since, there are 4 trsansactions only

        //base case 

        for (int i = 0; i < n; i++)
        {
            a[i][4] = 0;
        }
        for (int i = 0; i <=4; i++)
        {
            a[n][i] = 0;
        }

        for (int i = n-1; i >=0; i--)
        {
            for (int t = 0; t <= 3; t++)
            {
                int profit = 0;
                if(t%2==0){
                    profit = max(-p[i]+a[i+1][t+1],a[i+1][t]);
                }
                else{
                    profit = max(p[i]+a[i+1][t+1],a[i+1][t]);
                }
                a[i][t] = profit;
            }
        }
        cout<<a[0][0];

    }
}
