#include<bits/stdc++.h>
using namespace std;

void printMap(unordered_map <int,string> &m){
    cout<<"size : " << m.size()<<endl;
    for(auto &i : m){
        cout<<i.first<<" "<<i.second<<" "<<endl; //accessing - O(log n)
    }

}

int main(){
    

    //1.Internal implementation - using hash table 

    //2.Time complexity  avg tc is O(1) ,

    //valid keys datatype - limited datatype
    unordered_map <int,string> m; //not sorted but unique keys
    m[1]="abc";
    m[5]="cdc";  
    m[3]="acd"; //O(1)
    printMap(m);

    auto it = m.find(5);  //O(1) //returns m.end() if element is not present
    cout<<(*it).first<<" "<<(*it).second<<endl;
    
    m.erase(1); //O(1)
    printMap(m);


    return 0;
}