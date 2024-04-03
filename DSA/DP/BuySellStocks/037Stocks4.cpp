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

    int T = 1;//cin >> T;
    while (T--)
    {
        int n;cin>>n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin>>p[i];
        }

        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));
        
        // cout<<f(0,1,2,p,n,dp);


        int k=2;

        vector<vector<int>> dp(n+1,vector<int> (2*k+1,0));
        
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = 0; j <= 2*k; j++)
            {
                if(j%2==0){
                    dp[i][j] = max(-p[i]+dp[i+1][j+1],dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(p[i]+dp[i+1][j+1],dp[i+1][j]);
                }
            }
        }

        for(auto x : dp){
            for(auto c : x){
                cout<<c<<" ";
            }cout<<endl;
        }
        
        cout<<dp[0][2*k-1];
    }
}
