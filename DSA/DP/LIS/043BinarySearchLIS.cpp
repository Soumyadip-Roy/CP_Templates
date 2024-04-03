#include <bits/stdc++.h>
using namespace std;

#define all(v) 
signed main()
{   

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;cin >> T;
    while (T--)
    {
        int n;cin>>n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }

        // tc = O(N logN)
        // sc = O(N)
        
        vector<int> temp(n,1e9);
        temp[0] = v[0];
        for(int i = 1; i<n; i++){
            int k = lower_bound(temp.begin(),temp.end(),v[i]) - temp.begin(); // for equal elements
            temp[k] = v[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(temp[i]==1e9){
                break;
            }
            ans++;
        }
        cout<<ans;
    }
}
