#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int c = 0;
int s = 0;

void dfs(int vertex,vector<int> graph[],bool vis[]){
    vis[vertex]=1;
    for(int child : graph[vertex]){
        if(child==s)c++;
        if(vis[child])continue;
        dfs(child,graph,vis);
    }
}

int main(){
    int  T;cin>>T;
    while(T--){
        int n;cin>>n;
            c=0;s=0;

            vector<int> graph[N];
            bool vis[N]={0};
      
            for(int i = 1 ; i <=n; i++){
                int x;cin>>x;

                graph[x].push_back(i);
                graph[i].push_back(x);
            }

            int ct = 0;
            for(int i = 1 ; i <= n; ++i){
                if(vis[i]) continue;
                s=0;
                dfs(i,graph,vis);
                ct++;
            }

            cout<<c+1<<" "<<ct<<endl;
    }
    
    
    

    

    return 0;
}
