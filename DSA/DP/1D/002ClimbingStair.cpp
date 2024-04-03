#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(n==1) return 1;
    return f(n-1)+f(n-2);
}
//see lecture 7 recursion 
//shortcuts
//1. try to represent the problem in terms of INDEX 
//2. do all possible stuffs on the index according to the question
//3. count => sum up all steps 
//   min/max => min/max of all steps
 
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;
    vector<int> dp(n+1,-1);
    cout<<f(n);
}