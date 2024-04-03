// Code is like humour. When you have to explain it, it’s bad. //

// Author - royboylab

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(), v.end()

template <class T>
void coutfs(T x)
{
    for (auto i : x)
    {
        cout << i.first << " " << i.second << endl;
    }
}
template <class T>
void coutele(T x)
{
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
    }
}
