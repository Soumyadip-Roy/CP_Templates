#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+10;

int m[N];

signed main(){
    int n; cin>>n;
    vector<int> v(N,0);
    for (int i = 0; i < n; i++)
    {
        int x ; cin>>x;
        v[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        for(int j = i ; j<N ;j+=i){
            m[i]+=v[j];
        }
    }

    int t ; cin>>t;
    while(t--){
       
        int p , q;cin>>q>>q;
        int lcm = (p*q)/__gcd(p,q);
        int ans = m[p]+m[q];
        if(lcm<N){
            ans-=m[lcm];
        }
        cout<<ans<<"\n";
    }
    return 0;
}