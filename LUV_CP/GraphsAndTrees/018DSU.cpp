#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N], size[N];

void make(int n)
{
    par[n] = n;
    size[n] = 1;
}

int findPar(int v)
{
    if (par[v] == v)
    {
        return v;
    }
    par[v] = findPar(par[v]); //path compression 
    return par[v];
}

int Union(int a, int b)
{
    int pa = findPar(a);
    int pb = findPar(b);

    if (pa != pb)
    {
        //Union by size
        if (size[pa] < size[pb])
        {
            swap(a, b);
        }
        par[pb] = pa;
        size[pa] += size[pb];
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k; 

    for (int i = 1; i < N; i++)
    {
        make(i);
    }

    while (k--)
    {
        int u, v;
        cin >> u >> v;

        n -= Union(u, v);
    }
    int ans =0;

    for(int i = 0 ;i<n;i++){
        for(int j = i+1;j<n;j++){
            ans+= (size[i]*size[j]);
        }
    }
    cout<<ans;
    return 0;
}