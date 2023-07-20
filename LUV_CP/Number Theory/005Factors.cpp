#include<bits/stdc++.h>
using namespace std;

#define int long long

//O(sqrt(n))
int factors(int n){
    int ct = 0;
    int sum = 0;
    for(int i = 1 ; i *i <= n;i++){
          if(n%i==0){ct++;
          sum+=i;
          cout<<i<<' ';
          if(n/i!=i){
              cout<<n/i<<" ";
              ct++;sum+=n/i;}
          }
          
    }
    return ct /*, sum */;
}

signed main(){
    int n ; cin>>n;
    cout<<factors(n);
    return 0;
}