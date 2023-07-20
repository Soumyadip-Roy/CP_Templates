#include<bits/stdc++.h>
using namespace std;

//Sum of first n numbers 

//parameterised - print inside fn 
void sump(int n,int sum){
    if(n==0){
        cout<<sum;
        return;
    }
    sump(n-1,sum+n);
}

//functional - functiopn returns the answer - important in dp
int sumf(int n){
    if(n==0)return 0;
    return n + sumf(n-1);
}

//example - factorial of n;

int fact(int n){
    if(n==1 or n==0)return 1;
    return n*fact(n-1);
}

int main(){
        int n;cin>>n;
        sump(n,0);cout<<endl;
        cout<<sumf(n);cout<<endl;
        cout<<fact(n);
    return 0;
}