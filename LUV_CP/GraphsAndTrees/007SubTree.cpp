#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

//q=10^5 queries
//in each query - given V
//Print subtree sum of v and No of even numbers 



vector<int> tree[N];

//Precomputing SubtreeSum
int subtreeSum[N];
int even[N];

void dfs(int vertex, int parent = 0){
    //after entering the vertex
    subtreeSum[vertex]=vertex;  // or val[vertex] if given
    if(vertex%2==0){
        even[vertex]++;
    }
    for(int child : tree[vertex]){
        if(child==parent)continue;
        
        //before entering the child
        dfs(child,vertex);
        //after exiting ther child node 
        
        subtreeSum[vertex]+=subtreeSum[child];

        even[vertex]+=even[child];
        
    }
    //before exiting the vertex
}


int main(){
    
    int n; //n vertices
    cin>>n;

    for(int i = 0 ; i < n-1; i++){
        int x , y ;
        cin>>x>>y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1);
    int q ;cin>>q;
    while(q--){
        int v; cin>>v;
        cout<<subtreeSum[v]<<" ";
        cout<<even[v]<<" ";
    }
}
// 13 1 2 1 3 1 13 2 5 3 4 5 6 5 7 8 12 4 9 4 10 10 11 5 8

