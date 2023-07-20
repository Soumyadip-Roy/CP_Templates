#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> graph[N];

int vis[N];
int level[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty())
    {
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();
        for (auto child : graph[vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[vertex] + 1;
            }
        }
    }
}

//Time complexity - O(v+e)

int main()
{

    int n; //n vertices
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << level[i] << endl;
    }
}

// 13 1 2 1 3 1 13 2 5 3 4 5 6 5 7 8 12 4 9 4 10 10 11 5 8
