#include<bits/stdc++.h>
using namespace std;

void printVec(vector <int> &v){ 
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    } 
    cout<<endl;  
}


int main(){
    
    int n;
    cin>>n;
    
    //array whose elements are vector
    vector<int> v[n]; //no of columns are dynamic

    for (int i = 0; i < n; i++)
    {
        int m;
        cin>>m;
        for (int j = 0; j < m; j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printVec(v[i]);
    }
    return 0;
}