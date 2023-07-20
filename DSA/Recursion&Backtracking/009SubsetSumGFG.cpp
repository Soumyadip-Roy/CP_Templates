#include<bits/stdc++.h>
using namespace std;

//given a list of N integers , print sums of all subsets in it (in increasing order)
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
vector<int> sm;

void subseq(int i,vector<int> v,int a[],int n,int sum){
    if(i==n){
        sm.push_back(sum);
        return;
    }
    subseq(i+1,v,a,n,sum+a[i]);
    subseq(i+1,v,a,n,sum);
}
int main()
{
    int n = 4;
    int a[] = {1,2,5,3};
    vector<int> v; 

    sort(a,a+n);
    
    subseq(0,v,a,n,0);

    sort(sm.begin(),sm.end());

    for (int i = 0; i < sm.size(); i++)
    {
        cout<<sm[i]<<" ";
    }
    
    
}
