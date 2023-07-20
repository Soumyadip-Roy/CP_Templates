#include <bits/stdc++.h>
using namespace std;

//46 permutations - leetcode
vector<vector<int>> permutations;

//Approach 1
map<int,int> vis; // using a map to keep track of vsited elements

void generatePermutations(int ind,vector<int> v,vector<int> a,map<int,int> vis,int n){
    if(ind == n ){
        permutations.push_back(v);
        return;
    }

    for(int i=0;i<n;i++){
        if(!vis[a[i]]){
            vis[a[i]]=1;
            v.push_back(a[i]);
            generatePermutations(ind+1,v,a,vis,n);
            v.pop_back();
            vis[a[i]]=0;
        }
    }
}

//Approach 2 - swapping elements

void generatePermutations2(int ind,vector<int> a,int n){

    if(ind == n ){
        permutations.push_back(a);
        return;
    }

    for(int i=ind;i<n;i++){
        swap(a[ind],a[i]);
        generatePermutations2(ind+1,a,n);
        swap(a[ind],a[i]);
    }
}

//Time Complexity - O(n!*n)
//Space Complexity - O(n)

int main(){
    vector<int> a = {1,3,2};
    vector<int> v;

    generatePermutations2(0,a,3);
    generatePermutations(0,v,a,vis,3);

    for(auto x : permutations){
        for(auto p : x){
            cout<<p<<" ";
        }
        cout<<endl;
    }

}

