#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> graph[N];
bool vis[N]; //map<int,bool>vis;

void dfs(int vertex)
{
    //after entering the vertex
    vis[vertex] = 1;

    //if(vis[vertex]) return;

    for (int child : graph[vertex])
    {

        //before entering the child
        if (vis[child])
            continue;
        cout << vertex << " " << child << endl;

        dfs(child);
        //after exiting ther child node
    }
    //before exiting the vertex
}

//Time complexity - O(m+n)
// m recursive calls
// for loop runs 2*n times across all recursive calls

int main()
{

    int n, m; //n vertices , m edges
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    return 0;
}
