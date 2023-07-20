#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
//int graph[N][N];

vector<int> graph[N];

//if weights are given
vector<pair<int,int>> graph[N];

int main(){
    
    int n , m;
    cin>>n>>m;
    for(int i = 0 ; i < m; i++){
        int x , y ;
        cin>>x,y;

        int w ;cin>>w;

        // graph[x][y]=1;
        // graph[y][x]=1;

        // graph[x][y]=w;
        // graph[y][x]=w;

//------------------------------------------//

        graph[x].push_back(y);
        graph[y].push_back(x);

        // graph[x].push_back({y,w});
        // graph[y].push_back({x,w});

    //Adjacency Matrix
        //n=10^5
        //Space complexity => O(N^2)

    //Adjacency list 
        //n=10^5
        //Space complexity => O(m+n)

    //i , j  connected  , wt of i , j;

    //AMatrix - O(1)

    //if(graph[i][j]=1) connected
    //print(graph[i][j]) //weight 

    //AList - O(n)

    //for(auto child : graph[i]){
        //if(child==j) connected
        //print(child.second) //weight

    }
    return 0;
}