vector<vector<int>> dp(n,vector<int> (w+1,0));
        // tabulation

        for(int i=wt[0];i<=w;i++){
            dp[0][i] = v[0];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int notTake = dp[i-1][j];
                int take = 0;
                
                if(wt[i]<=w) take = v[i] + dp[i-1][j-wt[i]];

                dp[i][w] = max(take,notTake);
            }
        }
        cout<<dp[n-1][w]<<endl;