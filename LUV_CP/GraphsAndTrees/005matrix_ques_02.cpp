#include<bits/stdc++.h>
using namespace std;


void dfs(int i , int j ,vector<vector<char>>& grid , vector<vector<bool>> &vis){
    
    int m = grid.size();
    int n = grid[0].size();

    if(i<0 or j<0 or i>=m or j>=n )return; //invalid edge
    if(grid[i][j]!='1')return;
    vis[i][j]=1;
    dfs(i-1,j-1,grid,vis);
    dfs(i+1,j-1,grid,vis);
    dfs(i-1,j+1,grid,vis);
    dfs(i+1,j+1,grid,vis);
      
}

int numIslands(vector<vector<char>>& grid) {
    
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> vis(m,vector<bool> (n));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            vis[i][j]=0;
        }
    }

    int ct = 0;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(vis[i][j]==1)continue;
            dfs(i,j,grid,vis);
            ct++;
        }
     }
     return ct;
}

int main(){
    int m , n ;
    cin>>m>>n;
    vector<vector<char>> v(m,vector<char> (n));

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>v[i][j];
        }
    }
    cout<<numIslands(v);
    return 0;
}