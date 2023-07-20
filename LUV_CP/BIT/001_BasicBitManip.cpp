#include<bits/stdc++.h>
using namespace std;

void PrintBinary(int num){
    for (int i = 10; i >=0; i--)
    {
        cout<<((num >> i) & 1); //right shift the number by 10 , 9 , 8 ... 0 times resp
    }
    cout<<endl;
}

int main(){
  
    int a = 13;
    PrintBinary(a);

    int i = 3;
    if((a & (1<<i)) != 0)cout<<"set bit at "<<i<<"\n";

    //tilda
    PrintBinary(~a);

    //set bit
    i = 2;
    PrintBinary(a | 1<<i);

    //unset bit
    i = 3;
    PrintBinary(a & ~(1<<i));
    //PrintBinary(a ^ 1<<i); //same output but do not use

    //toogle 1->0 or 0->1
    i=5;
    PrintBinary(a ^ 1<<i);
    PrintBinary(a ^ 1<<4);

    //count setBits
    int setct = 0;
    for (int i = 31; i >=0 ; i--)
    {
        if((a & (1<<i)) != 0) setct++; 
    }
    cout<<setct<<"\n";

    cout<< __builtin_popcount(a)<<endl; //only for integers
    cout<< __builtin_popcountll((1ll<<64)-1)<<endl; //only for long

    //flip all bits of a number 
    int n=9;
    PrintBinary(n);
    n = n ^ UINT_MAX;
    PrintBinary(n);
    

    return 0;
}