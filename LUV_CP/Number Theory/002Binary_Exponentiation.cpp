#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
#define int long long

int binExpRec(int a , int b){
    if(b == 0) return 1;
    int res = binExpRec(a,b/2);
    if(b&1) return (a%M*(res*res)%M)%M;
    else return res*res;
}

int binExpItr(int a , int b){
    int ans = 1;
    while(b){
        if(b&1) ans=(ans * a)%M;// ith bit set
        b>>=1;
        a=(a*a)%M;
    }
    return ans;
}
signed main(){
    int a , b;
    cin>>a>>b;
    cout<<binExpRec(a,b)<<endl;
    cout<<binExpItr(a,b)<<endl;
    cout<<pow(a,b);
    
    return 0;
}