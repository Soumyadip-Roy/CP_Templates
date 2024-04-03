#include <bits/stdc++.h>
using namespace std;

int check(string s,string p){
    if(s.length()!=p.length()+1) return 0;
    int i = 0;
    int j = 0;

    while(i<s.length()){
        if(j<p.size() and s[i]==p[j]){
            i++;j++;
        }
        else{
            i++;
        }
    }
    if(i==s.size() and j==p.size())return 1;
    return 0;
}

bool comp (string a, string b){
    return a.length()<b.length();
}

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

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(),v.end(),comp);

        vector<int> dp(n,1);
        int mx = 0;
        for (int i = 1; i < n; i++)
        {
            for ( int previ = 0; previ < i; previ++)
            {
                if(check(v[i],v[previ])){
                    dp[i] = max(dp[i],1+dp[previ]);
                }
                mx = max(mx,dp[i]); 
            }
        }
        cout<<mx;
    }
}
