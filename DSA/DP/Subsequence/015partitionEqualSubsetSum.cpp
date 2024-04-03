#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+1;

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

    // THE  ONLY  CHANGE  IS  THIS 
    int t = s/2;
    if(s%2){
        cout<<0;
    }
    else{

    }

    // space optimization 
    vector<int> prev(t+1,0);
    vector<int> curr(t+1,0); 

    if(v[0]<=t)prev[v[0]]=1;
    prev[0]=curr[0]=1;

    for (int i = 1; i < n; i++)
    {
        
        for (int j = 1; j <= t; j++)
        {
            int notTake = prev[j];
            int take = 0;
            if(v[i]<=j) take = prev[j-v[i]];

            curr[j] = take or notTake;
        }
        prev = curr;    
    }
    cout<<prev[t];
}