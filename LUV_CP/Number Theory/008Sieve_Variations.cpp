#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+9;

//Sieve Vriations

vector <bool> isPrime(N,true);

//1. highest prime and lowest prime

vector <int> lp(N,0),hp(N,0); 

signed main(){

    isPrime[0]=isPrime[1]=false;

    for (int i = 2; i < N; i++)
    {
        if(isPrime[i]==true){
            hp[i]=lp[i]=i;//for primes
            for(int j = 2*i ; j<N ;j+=i){
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0)lp[j]=i;
            }
        }
    }
    /*for(int i = 1 ; i < 20 ;i++){
        cout<<i<<" "<<lp[i]<<" "<<hp[i]<<endl;
    }*/

//2. prime factorisation - log(n) - using hp or lp 
    int num;cin>>num;
    vector<int> prime_factors;
    unordered_map<int,int> pf_freq;
    

    while(num>1){
        int pf = hp[num];
        while(num%pf==0){
            num/=pf;
            prime_factors.push_back(pf);
            pf_freq[pf]++;
        }
    }
    /*for(auto f : prime_factors){
        cout<<f<<" ";
    }
    cout<<endl;
    for(auto f : pf_freq){
        cout<<f.first<<" "<<f.second<<endl;
    }*/

//3. Divisors
    vector<int> divisors[N];//i th vector will store divisors of i;

    for (int i = 1; i < N; i++)
    {
        for(int j = i ; j<N ;j+=i){
            divisors[j].push_back(i);
            }
    }
    for(int i = 0 ; i < 10 ;i++){
        for(auto i : divisors[i]){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}