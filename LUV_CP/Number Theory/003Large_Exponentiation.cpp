#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e18+7; // Large M 

int binExp(int a , int b){
    int ans = 1;
    // Large a (a<=10^18 a<=2^1024 )
    // a%=M;
    while(b){
        if(b&1) ans=binMultiply(ans,a)%M;
        b>>=1;
        a=binMultiply(a,a);
    }
    return ans;
}
//log^2(n); ==> while loop log(n) + binMultiply log(n)

//large a and M
int binMultiply(int a ,  int b){
    int ans = 0;
    while(b){
        if(b&1) ans=(ans + a)%M;
        b>>=1;
        a=(a+a)%M;
    }
    return ans;
}
signed main(){
    int a , b;
    cin>>a>>b;
    cout<<binExp(a,b)<<endl;
    cout<<pow(a,b);
    
    return 0;
}