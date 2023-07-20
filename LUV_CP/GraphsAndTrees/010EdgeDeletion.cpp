#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

// delete a edge in such a way that the product of sum of part 1 and part 2 are maximized 

vector<int> tree[N];
//Precomputing SubtreeSum
int subtreeSum[N];

void dfs(int vertex, int parent = 0){
   
    subtreeSum[vertex]=vertex; 

    for(int child : tree[vertex]){
        if(child==parent)continue;
    
        dfs(child,vertex);
        
        subtreeSum[vertex]+=subtreeSum[child];
    }
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
    int ans=0;
    for (int i = 2; i <= n; i++)
    {
        int p1 = subtreeSum[i];
        int p2 = subtreeSum[1]-p1;
        ans = max(ans,p1*p2);
    }
}
// 13 1 2 1 3 1 13 2 5 3 4 5 6 5 7 8 12 4 9 4 10 10 11 5 8

