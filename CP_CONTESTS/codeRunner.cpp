//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

int max(int a, int b){if (a > b)return a;else return b;}
int min(int a, int b){if (a < b)return a;else return b;}

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
        int n,k;cin>>n>>k;
        vector<int> v(n);
        vector<int> mx={0};
        vector<int> mn={0};

        int tot = 0;

        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            tot+=v[i];
        }

        sort(all(v));reverse(all(v));

        for (int i = 0; i < k; i++)
        {
            mx.push_back(v[i]);
        }
        
        for (int i = 1; i <=k; i++)
        {
            mx[i]+=mx[i-1];
        }
        
        int j = n-1;
        for(int i = 0;i<k;i++){
            mn.push_back(v[j]+v[j-1]);
            j-=2;
        }

        for (int i = 1; i <=k; i++)
        {
            mn[i]+=mn[i-1];
        }

        // coutele(mx),coutele(mn);

        int ans = 0;

        int i = 0;j=k;
        for(int l=0;l<=k;l++){
            ans=max(ans,tot-(mx[i]+mn[j]));
            i++;j--;
        }
        cout<<ans<<endl;
    }
}
