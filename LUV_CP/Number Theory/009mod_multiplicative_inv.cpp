#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M=1e9+7;


int binExp(int a , int b){
    int ans = 1;
    while(b){
        if(b&1) ans=(ans * a)%M;//ith bit set
        b>>=1;
        a=(a*a)%M;
    }
    return ans%M;
}

// nCr = n! / (n-r)! * r!

//n= 10^6 ,  k < n < 10^6
//q queries , q < 10^5

int fact [1000010];

signed main(){
    
    fact[0]=1;
    for(int i = 1 ; i < 1000000 ;i ++){
        fact[i] = (fact[i-1]*i)%M;
    }

    int q ; cin>>q;
    while (q--)
    {
        int n , r ; cin>>n>>r;

        int ans = fact[n];
        int den = (fact[n-r]*fact[r])%M;

        ans = ans * binExp(den,M-2);
        cout<<ans<<endl;
    }
    return 0;
}