#include <bits/stdc++.h>
using namespace std;

//top down approach 
int f(int n,vector<int> &dp,vector<int> a,int k){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if(n-i>=0) ans = min(ans,f(n-i,dp,a,k)+abs(a[n]-a[n-i]));  
    }       
    return dp[n]=ans;
}
int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;cin>>n>>k;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    vector<int> dp(n,-1); //size = n as 0 based indexing is used 
    //---------recursive 
    // cout<<f(n-1,dp,h,k);

    //--------iterative
    dp[0]=0;
    // for (int i = 1; i < n; i++)
    // {
    //     int ans = INT_MAX;
    //     for (int j=1; j <= k; j++)
    //     {
    //         if(i-j>=0)ans = min(ans,dp[i-j]+abs(h[i]-h[i-j]));
    //     }
    //     dp[i]=ans;
    // }
    // cout<<dp[n-1];

    // space optimization
    vector<int> prev(k,0);
    vector<int> curr(k,0);

    for (int i = 1; i < n; i++)
    {
        for(int j=0;j<k-1;j++){
            curr[j]=prev[j+1];
        }
        int ans = INT_MAX;
        for (int j=1; j <= k; j++)
        {
            if(i-j>=0)ans = min(ans,prev[k-j]+abs(h[i]-h[i-j]));
        }
        curr[k-1]=ans;
        prev=curr;
    }
    cout<<curr[k-1];
}