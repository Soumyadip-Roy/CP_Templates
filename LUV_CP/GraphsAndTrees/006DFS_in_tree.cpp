#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> tree[N];
int depth[N];  // distance from root vertex
int height[N]; // distance from lowest vertex

void dfs(int vertex, int parent = 0)
{
    // after entering the vertex

    for (int child : tree[vertex])
    {

        // before entering the child
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;

        dfs(child, vertex);
        // after exiting ther child node
        height[vertex] = max(height[vertex], height[child] + 1);
    }
    // before exiting the vertex
}

int main()
{

    int n; // n vertices
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " h: " << height[i] << " "
             << "d: " << depth[i] << endl;
    }
    return 0;
}
// 13 1 2 1 3 1 13 2 5 3 4 5 6 5 7 8 12 4 9 4 10 10 11 5 8
