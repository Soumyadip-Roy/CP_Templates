#include <bits/stdc++.h>
using namespace std;

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

int f(int i,int j, vector<int> v, vector<vector<int>> &dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn = 1e9;
    for(int idx = i;idx <= j; idx++){
        int cost = v[j+1]-v[i-1] + f(i,idx-1,v,dp)+ f(idx+1,j,v,dp);
        mn = min(mn,cost);
    }
    return dp[i][j] = mn;  
}

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
        int c;cin>>c;

        vector<int> v(c+2);
        v[0]=0;
        v[c+1] = n;
        for (int i = 1; i <=c; i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        vector<vector<int>> dp(c+2,vector<int> (c+2,-1));
        cout<<f(1,c,v,dp)<<endl;
    
    }
}
 