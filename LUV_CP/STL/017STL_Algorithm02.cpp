#include<bits/stdc++.h>
using namespace std;

bool isPositive(int x){
    return x>0;
}
int main(){

    //lambda function
    auto sum = [](int x , int y ){return x + y;};
    cout<<sum(2,4)<<endl;

    vector <int> v = {2,6,-1,5};
    cout<< all_of(v.begin(),v.end(),[](int x){return x>0;})<<endl; //if all are T the returns T else F
    cout<< all_of(v.begin(),v.end(),isPositive)<<endl;

    cout<< any_of(v.begin(),v.end(),[](int x){return x>0;})<<endl; //if any is T then returns T else F
    
    cout<< none_of(v.begin(),v.end(),[](int x){return x>0;})<<endl; //if all are F then returns T else F


    return 0;
}