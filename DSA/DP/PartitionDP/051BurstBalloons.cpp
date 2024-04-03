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
    int mx = 0;
    for(int idx = i;idx <= j; idx++){
        int cost = v[i-1]*v[idx]*v[j+1] + f(i,idx-1,v,dp)+ f(idx+1,j,v,dp);
        mx = max(mx,cost);
    }
    return dp[i][j] = mx;  
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

        vector<int> v(n+2);
        v[0]=1;
        v[n+1]=1;
        for (int i = 1; i <=n; i++)
        {
            cin>>v[i];
        }

        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        // cout<<f(1,n,v,dp)<<endl;

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i>j) continue; 
                int mx = 0;
                for(int idx = i;idx <= j; idx++){
                    int cost = v[i-1]*v[idx]*v[j+1] + dp[i][idx-1] + dp[idx+1][j];
                    mx = max(mx,cost);
                }
                dp[i][j] = mx;  
            }
        }

        cout<<dp[1][n];
    }
}
 