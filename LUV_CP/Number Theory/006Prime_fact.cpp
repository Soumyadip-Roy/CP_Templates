#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n ; cin>>n;
    vector<int> prime_factor;

    //O(sqrt(n))
    for (int i = 2; i*i < n; i++)
    {
        while(n%i==0){
            prime_factor.push_back(i);
            n/=i;
        }
    }
    if(n>1)prime_factor.push_back(n);//if a factor occour single time only at last
    
    for(auto i : prime_factor){
        cout<<i<<" ";
    }
    
      
    return 0;
}