#include<bits/stdc++.h>
using namespace std;

const int N=1e4;

vector<int> tree[N];
int depth[N];

void dfs(int v, int par = 0){

    for(int c : tree[v]){
        if(c==par)continue;
        depth[c]=depth[v]+1;
        dfs(c,v);
    }
}

int main(){
    int n;cin>>n; //no of vertices

    for (int i = 1; i <n; i++)
    {
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1);
    int max_depth = 0;
    int max_depth_node=1;
    for (int i = 1; i <= n; i++)
    {
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_depth_node=i;
        }
        depth[i]=0;
    }
    
    dfs(max_depth_node);
    int diameter = 0;

    for (int i = 1; i <= n; i++)
    {
        if(diameter<depth[i]){
            diameter=depth[i];
        }
    }
    cout<<diameter;
    return 0;
}
// 13 1 2 1 3 1 13 2 5 3 4 5 6 5 7 8 12 4 9 4 10 10 11 5 8
