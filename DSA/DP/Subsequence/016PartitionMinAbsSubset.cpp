#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;

int ans = 1e9;

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;

    vector<int> v(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];   
        s+=v[i];
    }

    vector<vector<int>> dp(n,vector<int> (s+1,-1));

    vector<int> prev(s+1,0);
    vector<int> curr(s+1,0); 

    prev[v[0]]=1;
    prev[0]=curr[0]=1;

    for (int i = 1; i < n; i++)
    {
        
        for (int j = 1; j <= s; j++)
        {
            int notTake = prev[j];
            int take = 0;
            if(v[i]<=j) take = prev[j-v[i]];

            curr[j] = take or notTake;
        }
        prev = curr;    
    }
    int ans = 1e9;
    for (int i = 0; i <= s/2; i++)
    {
        if(prev[i]){
            ans = min(ans,abs(i- abs(s-i)));
        }
    }
    cout<<ans;
}