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

    //vector whose elements are vector
    vector<vector <int>> v; //no of rows and columns ,both are dynamic

    for (int i = 0; i < n; i++)
    {
        int m;
        cin>>m;
        vector <int> temp;
        for (int j = 0; j < m; j++){
            int a;
            cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        printVec(v[i]);
    }
    return 0;
}