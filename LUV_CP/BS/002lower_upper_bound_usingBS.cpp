#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector <int> &v , int e){
    int lo = 0;
    int hi = v.size()-1;
    int mid;
    while(hi-lo> 1){
        mid = (hi+lo) /2;
        if(v[mid] < e)lo=mid+1;
        else hi=mid;
    }
    if(v[lo]>=e)return lo;
    if(v[hi]>=e)return hi;
    else return -1;
}
int upper_bound(vector <int> &v , int e){
    int lo = 0;
    int hi = v.size()-1;
    int mid;
    while(hi-lo> 1){
        mid = (hi+lo) /2;
        if(v[mid] <= e)lo=mid+1; //mid is eliminated from the search space 
        else hi=mid;
    }
    if(v[lo]>e)return lo;
    if(v[hi]>e)return hi;
    else return -1;
}

int main(){
    int n ; 
    cin>>n;
    vector <int> v(n);

    for (int i = 0; i < n; i++)cin>>v[i];
  
    int x;
    cin>>x;

    cout<< lower_bound(v,x);
    cout<< upper_bound(v,x);



    
    return 0;
}