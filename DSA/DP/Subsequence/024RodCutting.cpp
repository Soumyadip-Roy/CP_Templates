#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;

int f(int i, int wt, vector<int> &v,vector<int> &w, vector<vector<int>> &dp){

    if(i==0){
        return v[0]*(wt/w[0]);
    }

    if(dp[i][wt]!=-1){
        return dp[i][wt];
    }
    
    int notTake = 0  +f(i-1,wt,v,w,dp);
    int take = 0;
    if(w[i]<=wt){
        v[i] + f(i,wt-w[i],v,w,dp);
    }
    return dp[i][wt] = max(take,notTake);
}

signed main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--){
        int n,wt;
        cin>>n>>wt;

        vector<int> v(n);
        vector<int> w(n);
        
        for (int i = 0; i < n; i++)
        {
            v[i] = i+1;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>w[i];
        }

        vector<vector<int>> dp(n,vector<int> (wt+1,-1));

        cout<<f(n-1,wt,v,w,dp)<<endl;

        //tabulation        

        
    }
}