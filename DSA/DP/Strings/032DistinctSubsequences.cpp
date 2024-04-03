#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;

//1 based indexing is considered
int f(int i,int j, string s, string p, vector<vector<int>> &dp){

    if(j==0)return 1;
    if(i==0)return 0;

    if(s[i-1]==p[j-1]){
        return dp[i][j] = f(i-1,j-1,s,p,dp) + f(i-1,j,s,p,dp);
    }
    else{
        return dp[i][j] = f(i-1,j,s,p,dp);
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

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    // cout<<f(n,m,s,p,dp);

    for(int i = 0 ;i <= n; i++) dp[i][0] = 1; 
    for(int i = 1 ;i <= m; i++) dp[0][i] = 0;

    // dp[0][0] represents an empty string

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s[i-1]==p[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(auto x : dp){
    //     for(auto y : x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<dp[n][m];

    // vector<int> prev(m+1,0);
    // prev[0] = 1;
    // vector<int> curr(m+1,0);
    
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if(s[i-1]==p[j-1]){
    //             curr[j] = prev[j-1] + prev[j];
    //         }
    //         else{
    //             curr[j] = prev[j];
    //         }
    //     }
    //     prev = curr;
    // }

    // cout<<prev[m];
    //1d space optimization


    vector<int> prev(m+1,0);
    prev[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--) //reverse loop - since changed value is not required 
        {
            if(s[i-1]==p[j-1]){
                prev[j] = prev[j-1] + prev[j];
            }
        }
    }

    cout<<prev[m];


}