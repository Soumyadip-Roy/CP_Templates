#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue <int> pq;

    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(4);

    cout<<pq.top(); // returns max element in pq
    pq.pop(); //deletes the max element 
    return 0;
}