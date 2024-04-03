#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e3+1;

int f(int i, int t, vector<int> v,vector<vector<int>> &dp){
    if(t==0) return 1;
    if(i==0) return (v[0]==t);

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

    int n;cin>>n;
    int t;cin>>t;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];   
    }
    // vector<vector<int>> dp(N,vector<int> (N,-1)); for recursion  
    vector<vector<int>> dp(N,vector<int> (N,0)); //for tabulation 
    // int dp[n][target]
    cout<<f(n-1,t,v,dp)<<" ";


    //tabulation 
    for (int i = 0; i < n; i++)
        dp[i][0]=1;
    
    if(v[0]<=t)dp[0][v[0]]=1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            int notTake = dp[i-1][j];
            int take = 0;
            if(v[i]<=j) take = dp[i-1][j-v[i]];

            dp[i][j] = take + notTake;
        } 
    }
    cout<<dp[n-1][t];
 
    // space optimization 
    vector<int> prev(t+1,0);
    vector<int> curr(t+1,0); 

    if(v[0]<=t)prev[v[0]]=1;
    prev[0]=curr[0]=1;

    for (int i = 1; i < n; i++)
    {
        
        for (int j = 1; j <= t; j++)
        {
            int notTake = prev[j];
            int take = 0;
            if(v[i]<=j) take = prev[j-v[i]];

            curr[j] = take + notTake;
        }
        prev = curr;    
    }
    cout<<prev[t];
}