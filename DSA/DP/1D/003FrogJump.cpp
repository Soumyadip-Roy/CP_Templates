#include <bits/stdc++.h>
using namespace std;

//top down approach 
int f(int n,vector<int> &dp,vector<int> a){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int l = f(n-1,dp,a)+abs(a[n]-a[n-1]);
    int r = INT_MAX;
    if(n>1) r = f(n-2,dp,a)+abs(a[n]-a[n-2]);
    return dp[n]=min(l,r);
}
int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    vector<int> dp(n+1,-1); //size = n as 0 based indexing is used 

    // ---------recursive 
    cout<<f(n-1,dp,h);

    // --------iterative
    dp[0]=0;
    for (int i = 1; i <= n; i++)
    {
        int l = dp[i-1]+abs(h[i]-h[i-1]);
        int r = INT_MAX;
        if(i>1) r = dp[i-2]+abs(h[i]-h[i-2]);
        dp[i]=min(l,r);
    }
    cout<<dp[n-1];


    //space optimization
    int prev2=0,prev1=0;
    for (int i = 1; i < n; i++)
    {
        int l = prev1+abs(h[i]-h[i-1]);
        int r = INT_MAX;
        if(i>1) r = prev2+abs(h[i]-h[i-2]);
        int cur=min(l,r);
        prev2=prev1;
        prev1=cur;
    }
    cout<<prev1;
}