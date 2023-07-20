#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;

void generate (vector <int> &subset , vector<int> nums , int i=0){
   
    if(i==nums.size()){
        for(auto i : subset){
            cout<<i<<" ";
            }cout<<endl;
        subsets.push_back(subset);
        return;
    }
    //ith element is not in subset
    generate(subset,nums,i+1);

    //ith element in subset
    subset.push_back(nums[i]);
    generate(subset,nums,i+1);
    subset.pop_back();
    
}

int main(){
    vector<int> v;
    vector<int> n ={1,2,3}; 
    generate(v,n);
    return 0;
}