#include<bits/stdc++.h>
using namespace std;

void printVec(vector <pair<int,int>> &v){ 
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }   
}


int main(){
    
    //vector whose elements are pair
    vector<pair<int,int>> v = {{1,2} , {3,4}}; 

    v.push_back({8 , 9});
    
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   
        int x, y ;
        cin>>x>>y;
        v.push_back({x,y});
    } 
    cout<<endl;
    printVec(v);

    return 0;
}