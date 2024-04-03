#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

const int N = 1e3,M=100;

int n,m;

int grid[N][M];
int dp[N][M];

int minPath(int i,int j){
    //base cases 
    if(i>=n or j>=m){
        return INFINITY;
    }
    if(i==n-1 and j==m-1){
        return grid[i][j];
    }
    // this state has already been calculated 
    if(dp[i][j]!=-1){ 
        return dp[i][j];
    }
    // this state has never been calculated 
    return dp[i][j] = grid[i][j]+min(minPath(i+1,j),minPath(i,j+1));
}

//Time Complexity = O(nm)
//Space Complexity = O(nm)


signed main(){
    // memoization
    memset(dp,-1,sizeof(dp));

    int n;
    cin>>n;
    
    return 0;
}