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

int fact [1000010];

//ques - unlock the door hackeraarth

// ans = n! * kCn = kPr 
signed main(){
    
    fact[0]=1;
    for(int i = 1 ; i < 1000000 ;i ++){
        fact[i] = (fact[i-1]*i)%M;
    }

    int q ; cin>>q;
    while (q--)
    {
        int n , k ; cin>>n>>k;
        int ans = fact[k];
        int den = fact[k-n]%M;
        ans = ans * binExp(den,M-2);
        cout<<ans<<endl;
    }
    
    return 0;
}