#include<bits/stdc++.h>
using namespace std;

// subsequence - a contigous  / non contigous sequence which follows the order

//also see - power set algorithm 

//draw recursion tree - for better understanding

//technique involve  - take or do not take + multiple rec calls 

void subseq(int i,vector<int> v,int a[],int n){
    if(i==n){
        for (auto x : v)cout<<x<<" ";
        cout<<endl;
        return;
    }
    v.push_back(a[i]);
    subseq(i+1,v,a,n);
    v.pop_back();
    subseq(i+1,v,a,n);
    // subseq(i+1,v);
}

//time complexity = O(n * 2^n)
//space complexity = O(n)

int main(){
    int a[] = {3,1,2};
    int n = 3;

    vector<int> v={};
    subseq(0,v,a,n);
}
