#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;

int f(int i,int j, string s, string p, vector<vector<int>> &dp){

    if(j<0)return i+1;
    if(i<0)return j+1;

    if(s[i]==p[j]){
        return dp[i][j] = f(i-1,j-1,s,p,dp);
    }
    else{
        int insert = 1 + f(i,j-1,s,p,dp);
        int del = 1 + f(i-1,j,s,p,dp);;
        int replace = 1 + f(i-1,j-1,s,p,dp);

        return dp[i][j] = min({insert,replace,del});
    }
}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s,p;
    cin>>s>>p;
    int n = s.length();
    int m = p.length();

    vector<vector<int>> dp(n,vector<int> (m,-1));

    cout<<f(n-1,m-1,s,p,dp);
}