#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //stack <int> s;
    deque <int> d;

    queue <int> s;
    s.push(2);
    s.push(8);
    s.push(3);
    s.push(5);

    d.push_back(1);
    d.push_front(3);
    cout<<d[0]; // random access
    



    while(!s.empty()){
        //cout<<s.top()<<" "; //stack
        cout<<s.front()<<" "; //queue
        s.pop();
    }

    return 0;
}