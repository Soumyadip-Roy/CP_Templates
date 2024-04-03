#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e3+1;

int f(int i, int t, vector<int> v,vector<vector<int>> &dp){
    if(i==-1) 
    {
        if(t==0) return 1;
        return 0;
    }
    
    if(dp[i][t]!=-1){
        return dp[i][t];
    }
    
    int notTake = f(i-1,t,v,dp);
    int take = 0;
    if(v[i]<=t) take = f(i-1,t-v[i],v,dp);

    return dp[i][t] = (take + notTake);
}


signed main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int d;cin>>d;
        int totalsum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];  
            totalsum+=v[i]; 
        }

        int t = (totalsum-d)/2;
        if((totalsum-d)%2 or (totalsum-d)<0){
            cout<<T<<"this"<<totalsum<<" "<<d<<endl;
            // cout<<0;
            continue;
        }
        // vector<vector<int>> dp(n,vector<int> (t+1,-1));
        // cout<< f(n-1,t,v,dp)<<" "; 
        vector<vector<int>> dp(n,vector<int> (t+1,0));

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for (int i = 0; i < n; i++){
            dp[i][0]=1;
        }

        if(v[0]<=t)dp[0][v[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= t; j++)
            {
                int notTake = dp[i-1][j];
                int take = 0;
                if(v[i]<=j) take = dp[i-1][j-v[i]];

                dp[i][j] = (take + notTake);
            } 
        }
        cout<<dp[n-1][t]<<endl; 

        

    }
}