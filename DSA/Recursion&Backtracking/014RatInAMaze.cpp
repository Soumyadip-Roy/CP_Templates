#include <bits/stdc++.h>
using namespace std;

int vis[100][100];

vector<string> ans;
string s;
int m[10][20];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char dir[]={'U','D','R','L'};

void path(int n,int i=0,int j=0,char c= ' '){
    
    if(m[i][j]==0)return;
    if(i>=n or i<0 or j<0 or j>=n)return;
    if(vis[i][j])return;

    if(i==n-1 and j==n-1){
        s.push_back(c);
        ans.push_back(s.substr(1,s.length()+1));
        s.pop_back();
        return;
    }
    s.push_back(c);
    
    vis[i][j]=1;
    for (int it = 0; it < 4; it++)
    {
        path(n,i+dx[it],j+dy[it],dir[it]);
    }
    vis[i][j]=0;
    s.pop_back();
}

int main()
{  
    path(4);
    cout<<ans.size();
    sort(ans.begin(),ans.end());
    for(auto x : ans)cout<<x<<" ";
    
}
