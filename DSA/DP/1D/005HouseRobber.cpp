#include <bits/stdc++.h>
using namespace std;

int f(int n,vector<int> &dp,vector<int> &a){
    if(n<0) return 0;
    if(n==0) return a[0];

    if(dp[n]!=-1) return dp[n];
    int pick = a[n]+f(n-2,dp,a);
    int notpick = f(n-1,dp,a);
    return dp[n]=max(pick,notpick);
}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;
    vector<int> dp(n,-1);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    //recursive 
    // cout<<f(n-1,dp,a);


    //iterative 
    // dp[0]=a[0];

    // for (int i = 1; i < n; i++)
    // {
        
    //     int pick = a[i];
    //     if(i>1){
    //         pick+=dp[i-2];
    //     }
    //     int notpick = dp[i-1];
    //     dp[i]=max(pick,notpick);
    // }
    // cout<<dp[n-1];

    //space optimzation 
    int prev1=a[0],prev2=0,curr=0;
    for (int i = 1; i < n; i++)
    {
        int pick = a[i];
        if(i>1){
            pick+=prev2;
        }
        int notpick = prev1;
        curr=max(pick,notpick);
        prev2=prev1;
        prev1=curr;
    }
    cout<<curr;


}