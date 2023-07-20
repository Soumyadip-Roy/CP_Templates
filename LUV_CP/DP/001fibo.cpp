#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

const int N = 1e5;

int dp[N];

//TOP DOWN APPROACH - recursive

// int fibo(int n){
//     if(n==0)return 0;
//     if(n==1)return 1;
//     return fibo(n-1)+fibo(n-2);
// }    
// Time complexity - O(2^n)

int fibo(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(dp[n]!=-1) return dp[n];
    //memoise
    return dp[n] = fibo(n-1)+fibo(n-2);
}
//Time complexity - O(n)

signed main(){
    //memoization
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<fibo(n);

    // BOTTOM UP APPROACH -- iterative
    dp[0]=0;
    dp[1]=1;
    for(int i = 2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return 0;
}