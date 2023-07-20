#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    set <int> s; 
    //2 . in the case of map (works only for keys )
    //3. pairs (works only for keys )
    //strings !!

    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        s.insert(x);
    }
  
    for (int i :s )
    {
        cout<<i<<" ";
    }
    cout<<"\n";

    //auto it = lower_bound(s.begin(),s.end(),5); //never use this as this is O(n) opetation

    auto it = s.lower_bound(5); // this is log(n)
    if(it == s.end()) cout<<"Not Found"<<endl;
    else cout<<*it<<endl;


    string m = "lmaoxd";
    sort(m.begin(), m.end());
    cout<<m<<endl;
    auto i = lower_bound(m.begin(),m.end(),'a');
    cout<<*i;
    
    return 0;
}