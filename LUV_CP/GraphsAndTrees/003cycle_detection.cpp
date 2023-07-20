#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> graph[N];

bool vis[N];

bool dfs(int vertex , int par = 0){

    //after entering the vertex
    vis[vertex]=1;
    bool isLoopExists = 0;
    
    //if(vis[vertex]) return;
    
    for(int child : graph[vertex]){
        //before entering the 
        
        if(vis[child] and child == par )continue;
        if(vis[child]) return 1;

        isLoopExists |= dfs(child , vertex);
       
        //after exiting ther child node 
    }
    //before exiting the vertex
    return isLoopExists;
}

int main(){
    
    int n , m; //n vertices , m edges 
    cin>>n>>m;

    for(int i = 0 ; i < m; i++){
        int x , y ;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int isLoopExists = 0 ;
    for(int i = 1 ; i <= n; ++i){
        if(vis[i]) continue;
        if(dfs(i)){
            isLoopExists = 1;
            break;
        }

    }
    cout<<isLoopExists<<endl;
    
    return 0;
}
