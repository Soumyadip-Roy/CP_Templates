#include <bits/stdc++.h>
using namespace std;

int fibo(int n,vector<int> &dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;
    vector<int> dp(n+1,-1);
    //--------recursive---------
    //tc - O(n)
    //sc - O(n)+O(n) array + recursion stack

    // cout<<fibo(n,dp);

    //---------iterative--------
    dp[0]=0;
    dp[1]=1;
    // tc - O(n)
    // sc - O(n)
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];

    //space optimization ----------
    //sc=O(1)
    int prev1=0,prev2=1,cur = 0;
    for(int i=2;i<=n;i++){
        cur=prev1+prev2;
        prev1=prev2;
        prev2=cur;
    }
    cout<<cur<<" ";


}