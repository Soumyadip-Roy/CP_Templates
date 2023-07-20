#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
vector<int> graph[N];

int vis[8][8];
int level[8][8];

int getX(char x){
    return x-'a';
}
int getY(char x){
    return x-'0';
}
int bfs(string src, string dest){
    int srcX=getX(src[0]);
    int srcY=getY(src[1]);
    int destX=getX(dest[0]);
    int destY=getY(dest[1]);

    queue <pair<int,int>> q;
    while(!q.empty()){

    }

}

void reset(){
    for (int i = 0; i < 8; i++)
    {
        for(int j=0 ;j<8; j++){
            vis[i][j]=0;
            level[i][j]=0;            
        }
    }
    
}

int main(){
    int n;cin>>n;
    while(n--){
        string src,dest;
        cin>>src>>dest;

        cout<<bfs(src,dest)

    }
    return 0;
}