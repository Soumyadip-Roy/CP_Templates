#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Subset (vector<int> &v){
    int n = v.size();
    int sub = (1<<n);

    vector<vector<int>> subsets;
    for(int  mask = 0 ; mask < sub ; mask++){
        vector<int> subset;
        for(int i = 0 ; i < n ; i++){
            if(mask & (1<<i) != 0 )subset.push_back(v[i]);
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main(){
    
    int n ;
    cin>>n;
    vector <int> v(n);

    for (int i = 0; i < n ; i++)
    {
        cin>>v[i];
    }

    auto x = Subset(v);
    for(auto m : x ){
        for(auto i : m){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}