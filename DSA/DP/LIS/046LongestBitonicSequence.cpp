#include <bits/stdc++.h>
using namespace std;

signed main()
{
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

        vector<int> dplis(n,1);
        vector<int> dplds(n,1);


        for (int i = 0; i < n; i++)
        {
            for ( int previ = 0; previ < i; previ++)
            {
                if(v[i]>v[previ]){
                    dplis[i] = max(dplis[i],1+dplis[previ]);
                }
            }
        }
        for (int i = n-1; i >= 0; i--)
        {
            for (int previ = n-1; previ > i; previ--)
            {
                if(v[i]>v[previ]){
                    dplds[i] = max(dplds[i],1+dplds[previ]);
                }
            }
        }
        int mx = 1;

        for (int i = 0; i < n; i++)
        {
            mx = max(dplis[i]+dplds[i]-1,mx);
        }

        cout<<mx;
       
       
    }
}
