#include<bits/stdc++.h>
using namespace std;



int main(){
    

    vector <int> v = {4,5,3,6,7,8};
    //vector <int>::iterator it = v.begin();

    for (auto it = v.begin(); it!=v.end(); it++) //using auto keyword shortens the code
    {
        cout<<*it<<" "<<endl;
    }

    vector<pair<int,int>> v_p = {{1,2} , {3,4}};

    vector<pair<int,int>> :: iterator itt;

    for (itt = v_p.begin(); itt!=v_p.end(); itt++)
    {
        cout<<(*itt).first<<" "<<(*itt).second<<endl;
    }

    for (itt = v_p.begin(); itt!=v_p.end(); itt++)
    {
        cout<<itt->first<<" "<<itt->second<<endl;
    }


    //range based loops 

    for(int &i : v){
        cout<<i<<" ";
        i++;
    }
    cout<<endl;
    for(int &i : v){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto &i : v_p){
        cout<<i.first<<" "<<i.second<<endl;
    }


    //auto keyword
    auto a = 1.0;
    cout<<a;

    
    return 0;
}