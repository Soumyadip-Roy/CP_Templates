#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;

int f(int i, int w, vector<int> v,vector<int> wt,vector<vector<int>> &dp){
    
    // if(i==-1){
    //     return 0;
    // }
    if(i==0){
        if(wt[0]<=w)return v[0];
        return 0;
    }
    
    if(dp[i][w]!=-1){
        return dp[i][w];
    }
    
    int notTake = f(i-1,w,v,wt,dp);
    int take = 0; //INT_MIN
    if(wt[i]<=w) take = v[i] + f(i-1,w-wt[i],v,wt,dp);

    return dp[i][w] = max(take,notTake);
}


signed main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--){
        int n;
        cin>>n;

        vector<int> wt(n);
        vector<int> v(n);

        for(int i=0;i<n;i++){
            cin>>wt[i];
        }
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        int w;
        cin>>w;

        // vector<vector<int>> dp(n,vector<int> (w+1,-1));
        // cout<<f(n-1,w,v,wt,dp);

        vector<vector<int>> dp(n,vector<int> (w+1,0));
        // tabulation

        for(int i=wt[0];i<=w;i++){
            dp[0][i] = v[0];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int notTake = dp[i-1][j];
                int take = -1e9;
                    
                if(wt[i]<=j) take = v[i] + dp[i-1][j-wt[i]];
                    dp[i][j] = max(take,notTake);
            }
        }
        cout<<dp[n-1][w]<<endl;


        //space optimization

        vector<int> prev(w+1,0);
        vector<int> curr(w+1,0);

        for(int i=wt[0];i<=w;i++){
            prev[i]=v[0];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int notTake = prev[j];
                int take = -1e9;
                    
                if(wt[i]<=j) take = v[i] + prev[j-wt[i]];
                curr[j] = max(take,notTake);
            }
            prev = curr;
        }
        cout<<prev[w]<<endl;


        //space optimization 2.0


        // vector<int> prev(w+1,0);

        for(int i=wt[0];i<=w;i++){
            prev[i]=v[0];
        }

        for(int i=1;i<n;i++){
            for(int j=w;j>=0;j--){
                int notTake = prev[j];
                int take = -1e9;
                    
                if(wt[i]<=j) take = v[i] + prev[j-wt[i]];
                prev[j] = max(take,notTake);
            }
        }
        cout<<prev[w]<<endl;
    }
}