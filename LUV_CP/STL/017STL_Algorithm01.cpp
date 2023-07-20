#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector <int> a(n); 
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    //O(n)
    cout<<*min_element(a.begin()+3,a.end())<<" ";
    cout<<*max_element(a.begin(),a.end())<<" ";
    cout<<accumulate(a.begin(),a.end(),0)<<" ";
    cout<<count(a.begin(),a.end(),3)<<" ";

    reverse(a.begin(),a.end()); //same can be done with a string

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }    
    return 0;
}