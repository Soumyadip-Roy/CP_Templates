#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> dp,vector<vector<int>> tr){
    if(i==tr.size()-1){
        return tr[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int d = f(i+1,j,dp,tr);
    int dg = f(i+1,j+1,dp,tr);
    return dp[i][j]= tr[i][j]+min(d,dg);
}

// gives TLE on some test cases 

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;
    vector<vector<int>> tr;
    vector<vector<int>> dp(n,vector<int> (n,-1));


    for (int i = 0; i < n; i++)
    {
        vector<int> temp(i+1);
        for (int j = 0; j < i+1; j++)
        {
            cin>>temp[j];
        }
        tr.push_back(temp);
    }

    // cout<<f(0,0,dp,tr);

    //-------tabulation 

    //1.base case
    for (int i = 0; i < n; i++)
    {
        dp[n-1][i]=tr[n-1][i];
    }
    
    // 2.transistion 
    for (int i = n-2; i>=0; i--)
    {
        for (int j = 0; j <=i; j++)
        {
            dp[i][j]=tr[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout<<dp[0][0];

    //space optimization 
    vector<int> prev(n+1,0);
    vector<int> curr(n,0);
    
    for (int i = n-1; i>=0; i--)
    {   
        for (int j = 0; j <=i; j++)
        {
            curr[j]=tr[i][j]+min(prev[j+1],prev[j]);
        }
        prev=curr;
    }
    cout<<prev[0];
}  