#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> dp,vector<vector<int>> c){
    if(i<0 or j<0){
        return INT_MAX;
    }
    if(i==0 and j==0){
        return c[0][0];
    }
    if(dp[i][j]!=-1)
        return dp[i][j];

    return dp[i][j] = c[i][j]+min(f(i-1,j,dp,c),f(i,j-1,dp,c));
}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;cin>>n>>m;
    vector<vector< int>> mat(n,vector<int> (m));

    for (int i = 0; i < n; i++)
    {
        for(int j=0 ; j<m ;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int> (m,-1));
    cout<<f(n-1,m-1,dp,mat);

    //---------iterative
    dp[0][0]=mat[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        { 
            if(i or j){ 
                int x=INT_MAX,y=INT_MAX;
                if(i>0)x=dp[i-1][j];
                if(j>0)y=dp[i][j-1];
                dp[i][j]=mat[i][j]+min(x,y);
            }
        }
    }
    cout<<dp[n-1][m-1];

    //----------space optimization
    vector<int> prev(m,INT_MAX);
    vector<int> curr(m,0);
    curr[0]=mat[0][0];
    for (int i = 0; i < n; i++)
    {
        for(int j =  0; j<m ;j++){
            if(i or j){
                int x=INT_MAX,y=INT_MAX;
                x=prev[j];
                if(j>0)y=curr[j-1];
                curr[j]=mat[i][j]+min(x,y);
            }
        }
        prev=curr;
    }
    cout<<prev[m-1];
}