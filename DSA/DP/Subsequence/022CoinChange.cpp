#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;

int f(int i, int t, vector<int> d, vector<vector<int>> &dp){
    
    if(i==0){
        if(t%d[0]==0){
            return 1;
        }
        else return 0;
    }

    if(dp[i][t]!=-1){   
        return dp[i][t];
    }

    int notTake = f(i-1,t,d,dp);
    int take = 0;
    if(d[i]<=t){
        take = f(i,t-d[i],d,dp);
    }
    
    return dp[i][t] = take + notTake;
}

signed main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--){
        int n,t;
        cin>>n>>t;

        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            cin>>d[i];
        }


        vector<vector<int>> dp(n,vector<int> (t+1,-1));

        cout<<f(n-1,t,d,dp)<<endl;

        //tabulation        

        
    }
}