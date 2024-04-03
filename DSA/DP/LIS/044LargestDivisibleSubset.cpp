#include <bits/stdc++.h>
using namespace std;

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
        sort(v.begin(),v.end());

        vector<int> dp(n,1);
        int mx = 1;

        vector<int> hash(n);
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
        }
        
        for(int i = 1 ; i<n ;i++){
            for(int previ = i-1; previ>=0; previ--){
                if(v[i]%v[previ]==0){
                    if(dp[i] < 1+dp[previ]){
                        dp[i] = 1 + dp[previ];
                        hash[i] = previ;
                    }
                    mx = max(mx,dp[i]);

                }
            }
        }
        
        int start = -1;
        
        for (int i = n-1; i>=0; i--)
        {
            if(dp[i]==mx){
                start = i;
                break;
            }
        }
        vector<int> ans(1,v[start]);
        int j = start;

        while(hash[j]!=j){
            j=hash[j];
            ans.push_back(v[j]);
        }
        
        // for (int i = 0; i < ans.size(); i++)
        // {
        //    cout<<ans[i];
        // }
        
        // for printing use hash -- (backtracking)
        // if condition is true store the prev_index at the hash[curr_index]
        // backtrack later
    }
}
