#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;


int f(int i,int j, string s, string p, vector<vector<int>> &dp){

    if(i<0 or j<0){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s[i]==p[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,p,dp);
    }
    return dp[i][j] = max(f(i,j-1,s,p,dp),f(i-1,j,s,p,dp));
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


    // vector<vector<int>> dp(n,vector<int> (m,-1));

    // cout<<f(n-1,m-1,s,p,dp);

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for (int i = 0; i < m; i++) dp[0][i] = 0;
    for (int i = 0; i < n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s[i-1]==p[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    
    cout<<dp[n][m];
    //space optimization
    
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s[i-1]==p[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else curr[j] = max(curr[j-1],prev[j]);
        }
        prev = curr;
    }
    cout<<prev[m];
    // print lcs 
    // dp 26

    // print lc substring   
    // dp 27 
    

    //print lc supersequence
    int i = n , j = m;
	
	string ans = "";

    while(i>0 and j>0){
        if(s[i-1]==p[j-1]){
            ans.push_back(s[i-1]);
            i--;j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(s[i-1]);
                i--;
            }
            else{
				ans.push_back(p[j-1]);
                j--;
            }
        }
    }
	while(i>0){
		ans.push_back(s[i-1]);
		i--;
	}

	while(j>0){
		ans.push_back(p[j-1]);
		j--;
	}
    cout<<ans;
	cout<<to_string(ans.size());
 
}