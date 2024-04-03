#include <bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> &mt,vector<vector<int>> &dp){
    int n = mt.size();
    int m = mt[0].size();
    if(j<0 or j>m-1)
        return -1e5;
    if(i==n-1)
        return mt[i][j];
    if(dp[i][j]!=-1e5){
        return dp[i][j];
    }
    int dn = mt[i][j]+f(i+1,j,mt,dp);
    int ldg = mt[i][j]+f(i+1,j+1,mt,dp);
    int rdg = mt[i][j]+f(i+1,j-1,mt,dp);

    return dp[i][j] = max(dn,max(ldg,rdg));
}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;cin>>n>>m;

    vector<vector<int>> matrix(n,vector<int> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int> (m,-1e5));
    int ans = -1e5;

    for (int i = 0; i < m; i++)
    {
        ans = max(ans,f(0,i,matrix,dp));
    }
    cout<<ans<<endl;

    //-------------iterative  
    for (int i = 0; i < m; i++)
    {
        dp[n-1][i]=matrix[n-1][i];
    }
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int dn= -1e9,ldg=-1e9,rdg=-1e9;

            dn = dp[i+1][j];
            if(j>0)ldg = dp[i+1][j-1];
            if(j<m-1)rdg = dp[i+1][j+1];
            dp[i][j] = matrix[i][j]+max(dn,max(ldg,rdg));
        }
    }

    ans = -1e9;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans,dp[0][i]);
    }
    cout<<ans<<endl;

    //----------Space optimization 
    vector<int> prev(m,0);
    vector<int> curr(m,0);

    for (int i = 0; i < m; i++)
    {
        prev[i]=matrix[n-1][i];
    }

    for (int i = n-2; i >=0; i--)
    {
        for (int j = m-1; j>=0; j--)
        {   
            int dn= -1e9,ldg=-1e9,rdg=-1e9;
            dn = prev[j];
            if(j>0)ldg = prev[j-1];
            if(j<m-1)rdg = prev[j+1];

            curr[j]=matrix[i][j]+max(dn,max(ldg,rdg));
        }
        prev = curr;
    }
    
    ans = -1e9;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans,prev[i]);
    }
    cout<<ans<<endl;
}
