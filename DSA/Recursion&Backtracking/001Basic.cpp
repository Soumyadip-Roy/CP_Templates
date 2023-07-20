#include<bits/stdc++.h>
using namespace std;

//1- Print linearly from 1 to n

void fun1(int i,int n){
    if(i>n) return;
    cout<<i;
    fun1(i+1,n);
}

//2- Print linearly from n to 1

void fun2(int i,int n){
    if(i<n)return;
    cout<<i;
    fun2(i-1,n);
}

//3- Print linearly from 1 to n(with backtracking)

void fun3(int n){
    if(n==0)return;
    fun3(n-1);
    cout<<n;
}

//3- Print linearly from n to 1(with backtracking)

void fun4(int n){
    if(n==0)return;
    cout<<n;
    fun4(n-1);
}


int main(){
    int n;cin>>n;
    fun1(1,n);
    cout<<endl;
    fun2(n,1);
    cout<<endl;
    fun3(n);
    cout<<endl;
    fun4(n);
}
