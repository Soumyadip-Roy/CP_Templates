#include<iostream>
#include<vector>
using namespace std;

void printVec(vector <int> &v){ //pass by reference is less expensive operation (saves O(n) time )
    for (int i = 0; i < v.size(); i++)    //v.size() -> O(n)   
    {
        cout<<v[i]<<" ";
    }
    cout<<endl; 
}

int main(){
    
    vector <int> v(5,7);

    v.push_back(8);
    printVec(v);

    v.pop_back();
    printVec(v);

    vector <int> v2 = v ; // O(n) , expensive operation
    //v2 is a copy of v . if we change v2 no change in v



    return 0;
}