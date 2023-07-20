#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,string> p;

    p={1,"abcd"};
    //cout<<p.first;
    //cout<<p.second;

    //array whose elements are pair
    pair <int , int> arr[3];  // arr= {{1,2},{5,6},{7,8}}
    arr[0] = {1,2}; //each element of the array is a pair
    arr[1] = {5,6};
    arr[2] = {7,8};
    
    swap(arr[0],arr[2]);

    for (int i = 0; i < 3; i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
    


    return 0;
}