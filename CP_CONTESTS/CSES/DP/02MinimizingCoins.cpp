// Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

const int M = 1e9,N=12;

vector<int> dp(N+1,M);
int n;

int noOfCoins(int x,int a[]){
    if(x==0){
        return 0;
    }
    if(x<0){
        return M;
    }
    int mn=M;
    for (int i = 0; i < n; i++)
    {
        mn = min(noOfCoins(x-a[i],a),mn);
    }
    return dp[x]=1+mn;
}

signed main()   

{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  

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
        
        int a[] = {1,3,5};
        n=3;
        cout<<noOfCoins(1,a);
        coutele(dp);
    }
}
