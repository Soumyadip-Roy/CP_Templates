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
    sort(a.begin(), a.begin());

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    auto it = lower_bound(a.begin(),a.end(),77); //returns a pointer 
    if(it == a.end()) cout<<"Not Found";
    else cout<<*it;
    
    return 0;
}