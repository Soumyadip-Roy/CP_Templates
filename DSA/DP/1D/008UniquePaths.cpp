#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> dp,int n,int m)
{
    if(i<0 or j<0){
        return 0;
    }
    if(i==0 and j==0){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up = f(i-1,j,dp,n,m);
    int left = f(i,j-1,dp,n,m);
    return dp[i][j] = up+left;

}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int m,n;cin>>m>>n;
    vector<vector<int>> dp(m,vector<int> (n,-1));
    cout<<f(m-1,n-1,dp,m,n);

    dp[0][0]=1;
    for (int i = 0; i < m; i++)
    {
        for(int j=0 ; j<n ;j++){
            if(i){
                dp[i][j] = dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];
            }        
            if(j){
                dp[i][j] = dp[i][j-1];
                if(i) dp[i][j] += dp[i-1][j];
            }        
        }
    }
    cout<<dp[m-1][n-1];

    vector<int> prev(n,0);
    vector<int> curr(n,0);
    prev[0]=1;
    for (int i = 0; i < m; i++)
    {
        for(int j=0 ; j<n ;j++){
            curr[j]=prev[j];
            if(j)curr[j]+=curr[j-1];
        }
        prev=curr;
    }
    cout<<prev[n-1];
}