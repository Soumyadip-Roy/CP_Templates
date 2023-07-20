#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9+7; 

// b<=10^18

int binExp(int a , int b , int m){
    int ans = 1;
    while(b){
        if(b&1) ans=(ans * a)%m;// ith bit set
        b>>=1;
        a=(a*a)%M;
    }
    return ans;
}

signed main(){
    int a , b; cin>>a>>b;

    cout<<binExp(50,binExp(64,32,M-1),M);
    
    return 0;
}