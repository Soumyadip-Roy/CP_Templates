#include<bits/stdc++.h>
using namespace std;

void dfs(int i , int j , int initcol , int newColor,vector<vector<int>>& image){
    
    int n = image.size();
    int m = image[0].size();

    if(i<0 or j<0 or i>=n or j>=m )return; //invalid edge

    if(image[i][j]!=initcol)return;//invalid edge
    
    image[i][j]=newColor;
    dfs(i-1,j-1,initcol,newColor,image);
    dfs(i+1,j-1,initcol,newColor,image);
    dfs(i-1,j+1,initcol,newColor,image);
    dfs(i+1,j+1,initcol,newColor,image);
 
      
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if(image[sr][sc]!=newColor){
        dfs(sr,sc,image[sr][sc],newColor,image);
    }
    return image;
}

int main(){
    
    return 0;
}