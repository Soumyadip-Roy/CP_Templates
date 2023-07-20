#include<bits/stdc++.h>
using namespace std;

// 39. combination sum leetcode 

//logic 1 for array problems pick or not pick 

vector<vector<int>> ans;

void subseq(int i,vector<int> &v,int a[],int n,int t){

    if(i==n){
        if(t==0){
            ans.push_back(v);
        }
        return;
    }

    if(a[i]<=t){
        v.push_back(a[i]);
        subseq(i,v,a,n,t-a[i]); //take the same element multiple times, index remains i
        v.pop_back();
    }

    subseq(i+1,v,a,n,t);
}

//time complexity  -  O(2^n * k)
//space complexity  -  O(k x) 
//k is avg size of sequence , x is number of sequences. 

int main()
{
    int n = 5;
    int a[] = {1,2,3,4,1};
    int t = 4;

    vector<int> v = {};

    subseq(0,v,a,n,t);
    cout<<ans.size();
    for(auto x: ans){
        for(auto p : x){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}
