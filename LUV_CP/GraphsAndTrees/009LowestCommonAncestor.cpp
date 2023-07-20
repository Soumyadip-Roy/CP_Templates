#include<bits/stdc++.h>
using namespace std;

const int N=1e4;

vector<int> tree[N];
int depth[N];

int par[N];

void dfs(int v , int p=0){
    par[v]=p;
    for(auto c:tree[v]){
        if(c==p)continue;
        dfs(c,v);
    }
}

vector<int> path(int v){
    vector<int> ans;

    while(v != 0){
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    int x,y;cin>>x>>y;

    vector<int> pathx = path(x);
    vector<int> pathy = path(y);

    int k = min(pathx.size(),pathy.size());

    int lca = -1;

    for (int i = 0; i < k; i++)
    {
        if(pathx[i]!=pathy[i])break;
        else lca=pathx[i];
    }
    cout<<lca;
    return 0;
}
// 13 1 2 1 3 1 13 2 5 3 4 5 6 5 7 8 12 4 9 4 10 10 11 5 8
