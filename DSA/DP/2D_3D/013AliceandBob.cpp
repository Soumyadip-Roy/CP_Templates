#include <bits/stdc++.h>
using namespace std;

int f(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    int n = grid.size();
    int m = grid[0].size();

    if(j1<0 or j1>=m or j2<0 or j2>=m) return -1e9;
    if(i==n-1){
        if(j1!=j2)return grid[i][j1]+grid[i][j2];
        else return grid[i][j1];    
    }
    if(dp[i][j1][j2]!=-1e9){
        return dp[i][j1][j2];
    }

    int ans = -1e9;
    for (int di = -1; di < 2; di++)
    {
        for (int dj = -1; dj < 2; dj++)
        {   int val= 0;
            if(j1==j2) val = grid[i][j1];
            else val =  grid[i][j1]+grid[i][j2];
            ans = max(ans,val+f(i+1,j1+di,j2+dj,grid,dp));

        }
    }
    return dp[i][j1][j2] = ans;
}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int r,c;cin>>r>>c;
    vector<vector<int>> grid(r,vector<int> (c));
    vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,-1e9)));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>grid[i][j];
        }
    }
    // cout<<f(0,0,c-1,grid,dp);

    // -------tabulation 

    //base case 
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if(j1!=j2)dp[r-1][j1][j2] = grid[r-1][j1]+grid[r-1][j2];
            else dp[r-1][j1][j2] = grid[r-1][j1];
        }
    }


    for (int i = r-2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int ans = -1e8;
                for (int di = -1; di < 2; di++)
                {
                    for (int dj = -1; dj < 2; dj++)
                    {   
                        int val= 0;
                        if(j1==j2) val = grid[i][j1];
                        else val =  grid[i][j1]+grid[i][j2];

                        if(j1+di<0 or j1+di>=c or j2+dj<0 or j2+dj>=c){
                            // val+=-1e8;
                        }
                        else{
                            ans = max(ans,val+dp[i+1][j1+di][j2+dj]);
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        } 
    }

    for (int i = 0; i < r; i++)
    {
        for (int j1 = 0; j1<c; j1++)
        {
            for (int j2 = 0; j2<c; j2++)
            {
                cout<<dp[i][j1][j2]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    cout<<dp[0][0][c-1];



    // Space optimzation 

    vector<vector<int>> prev(c,vector<int> (c));
    vector<vector<int>> curr(c,vector<int> (c));

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(i!=j) prev[i][j] = grid[r-1][i]+grid[r-1][j];
            else prev[i][j] = grid[r-1][i];
        }
    }
    
    for (int i = r-2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int ans = -1e8;
                for (int di = -1; di < 2; di++)
                {
                    for (int dj = -1; dj < 2; dj++)
                    {   
                        int val= 0;
                        if(j1==j2) val = grid[i][j1];
                        else val =  grid[i][j1]+grid[i][j2];

                        if(j1+di<0 or j1+di>=c or j2+dj<0 or j2+dj>=c){
                            // val+=-1e8;
                        }
                        else{
                            ans = max(ans,val+prev[j1+di][j2+dj]);
                        }
                    }
                }
                curr[j1][j2] = ans;
            }
        }
        prev=curr; 
    }
    cout<<prev[0][c-1];
}