#include <bits/stdc++.h>
using namespace std;


// int f(int n,int last,vector<vector<int>> &dp,vector<vector<int>> &p){
//     if(n==0){
//         int mx = 0;
//         for (int t = 0; t < 3; t++)
//         {
//             if(t!=last){
//                 mx = max(mx,p[0][t]);
//             }
//         }
//         return dp[0][last]=mx;
//     } 
//     if(dp[n][last]!=-1) return dp[n][last];

//     int mx = 0;
//     for (int t = 0; t < 3; t++)
//     {
//         if(t!=last){
//             int pt = p[n][t]+f(n-1,t,dp,p);
//             mx = max(mx,pt);
//         }
//     }
//     return dp[n][last]=mx;
// }   

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;cin>>n;
    vector<vector<int>> dp(n,vector<int> (4,-1));
    vector<vector<int>> points;
    

    for (int  i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < 3; j++)
        {
            int p;cin>>p;
            v.push_back(p);
        }
        points.push_back(v);
    }

    // cout<<f(n-1,3,dp,points)<<endl;

    // //-----------iterative---------
    
    // dp[0][0]=max(points[0][1],points[0][2]);
    // dp[0][1]=max(points[0][0],points[0][2]);
    // dp[0][2]=max(points[0][0],points[0][1]);
    // dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    // for (int i = 1; i < n; i++)
    // {
    //     for (int last = 0; last < 4; last++)
    //     {
        
    //         int mx = 0;
    //         for (int t = 0; t < 3; t++)
    //         { 
    //             if(t!=last)
    //                 mx = max(mx,points[i][t]+dp[i-1][t]);
    //         }
    //         dp[i][last]=mx;
    //     }
    // }

    // cout<<dp[n-1][3];
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //space optimization
    vector<int> prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(4,0);
        for (int last = 0; last < 4; last++)
        {
            int mx = 0;
            for (int t = 0; t < 3; t++)
            { 
                if(t!=last)
                    mx = max(mx,points[i][t]+prev[t]);
            }
            curr[last]=mx;
        }
        prev=curr;
    }
    cout<<prev[3];
}
