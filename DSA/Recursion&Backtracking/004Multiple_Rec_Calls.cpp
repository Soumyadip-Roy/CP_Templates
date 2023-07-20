#include <bits/stdc++.h>
using namespace std;

// Fibonacci 
// 0 1 1 2 3 5 8 13 21 34 

int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

//time complexity = O(2^n)
//space complexity = O(n)

int main(){
    cout<<fibo(6);
}
