//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

void dfs(int v,vector<int> vis,vector<int> g[],set<int> st)
{
    vis[v] = 1;
    for (int child : g[v])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}   

signed main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;cin >> T;
    while (T--)
    {
        int n;cin>>n;  

        vector<int> vis(n,0);
        set<int> st;
        vector<int> g[n];

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        for(int i=1;i<=n;i++){
            dfs()
        }

        
    }
}
