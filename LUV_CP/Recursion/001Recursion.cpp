#include<bits/stdc++.h>
using namespace std;

void func(int n){
    if(n==0)return;
    func(n-1);
    //for (size_t i = 0; i < count; i++)
    cout<<n<<" ";
    //func(n-1);

}

int main(){
    func(5);
    return 0;
}

// O(n^2) (no of function call x complexity of each function)