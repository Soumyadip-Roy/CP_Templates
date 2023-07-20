#include<bits/stdc++.h>
using namespace std;

void printMap(map<int,string> &m){
    cout<<"size : " << m.size()<<endl;
    for(auto &i : m){
        cout<<i.first<<" "<<i.second<<" "<<endl; //accessing - O(log n)
    }

}

int main(){
    
    map<int,string> m; //sorted and unique keys
    m[1]="abc";  //each key is compared to other during insertion
    m[5]="cdc";  //insertion - O(log n)
    m[3]="acd";
    m[6]; //defalut string is empty , int is 0 , vector is empty;
    printMap(m);

    //m["abcd"]="abcd"   //insertion - string.size() * log(n)


    auto it = m.find(5);  //O(log n) //returns m.end() if element is not present
    if (it != m.end())
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    
    m.erase(1);//O(log n)
    printMap(m);


    return 0;
}