#include<bits/stdc++.h>
using namespace std;

int lcm(int a , int b){
    return (a*b)/gcd(a,b);
}

int main(){

    //a*b = lcm(a,b) * gcd(a,b) 

    int a , b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    cout<<lcm(a,b)<<endl;
    cout<<__gcd(a,b)<<endl;
    
    cout<<gcd(12 , gcd(18 , 20));

    return 0;
}

