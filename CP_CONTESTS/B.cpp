//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

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

        int a[] = {6,0,4,5,1,3,2,0,0,5,1,0,3,4,0,0,5,0,1,0};

        vector<int> v(n);
        int j=0;
        for (int i = 0; i < n; i++)
        {
            v[i]=a[j++%20];
        }
        coutele(v);
        int mx = 0;
        int mn = UINT_MAX;
        for(int i=0;i<20;i++){
            int sum = 0;
            for(int j=i;j<9+i;j++){
                sum+=v[j];
            }
            mx = max(mx,sum);
            mn = min(mn,sum);
        }
        cout<<mx<<" "<<mn;
    }
}
