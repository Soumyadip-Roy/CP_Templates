/* BS can be applied to  - 
    1.any monotonic function (increasing or decreasing array)
    2.x^2 is also monotonic
    3.on any predicate function(T or F) which is monotonic (eg - TTTTFFF or FFFFTTT)
*/
#include<bits/stdc++.h>
using namespace std;

void search(int x, int n , vector<int> &v){
    int lo = 0 ;
    int hi = n-1;  
    int mid;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(v[mid]<x) lo=mid+1;
        else hi=mid;
    } 
    if(v[lo]==x)cout<<lo;
    else if(v[hi]==x)cout<<hi;
    else cout<<"Not Found";
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int x;
    cin>>x;
    search(x , n , v);
    
    
    return 0;
}