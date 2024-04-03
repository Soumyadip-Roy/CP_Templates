// Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

const int M = 1e9+7,N=10;

vector<int> dp(N+1,-1);

int noOfWays(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0 ){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    for (int i = 1; i <= 6; i++)
    {   
        dp[n]+=noOfWays(n-i);
        
    } 
    return dp[n];
}

signed main()   

{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  



    //iterative 
    dp[0]=0;
    dp[1]=1;

    // for (int i = 2; i < N; i++)
    // {       
    //     int k=6;
    //     if(i<=6){
    //         k=i-1;
    //     }

    //     for(int j=1;j<=k;j++){
    //         dp[i]+=dp[i-j]%M;
    //     
    // }

    int T = 1;//cin >> T;
    while (T--)
    {
        int n;cin>>n;
        // cout<<dp[n+1]%M;
        cout<<noOfWays(n);
    }
}
