#include <bits/stdc++.h>
using namespace std;

void PrintBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1); //right shift the number by 10 , 9 , 8 ... 0 times resp
    }
    cout << endl;
}

int main()
{
    //even otr odd
    int n = 8;
    for (int i = 0; i < n; i++)
    {
        PrintBinary(i);
        //result will be either 0 or 1 , since we are doing and with 0000000001 , no is even if zeroth bit is 0 , odd if 1 .
        if (i & 1)
            cout << "odd\n"; //last bit of the result is 1(ie result will always be 1)
        else
            cout << "even\n";
    } //last bit of the result is 0(ie result will always be 0)

    //mmultiply divide by 2
    n = 5;
    cout << (n >> 1) << endl;
    cout << (n << 1) << endl;

    for (char c = 'A'; c <= 'C'; c++)
    {
        cout << c << " : ";
        PrintBinary(int(c));
    }
    for (char c = 'a'; c <= 'c'; c++)
    {
        cout << c << " : ";
        PrintBinary(int(c));
    }

    char A = 'A';
    char a = A | (1 << 5);
    cout << a << endl;
    char aA = a & ~(1 << 5);
    cout << aA << endl;

    // (1<<5 is the binary of ascii value of space )
    //UPPERCASE to lowercase
    cout << char('C' | ' ') << endl;
    // the binary of ascii of _ is 1011111
    //lowercase to UPPERCASE
    cout << char('c' & '_') << endl;

    //clear msb

    n = 59;
    PrintBinary(n);
    //unset lsb upto ith bit
    int i = 4;
    int b = n & 1<<(i+1) ;  //~(100000-1 is 011111) is 100000
    PrintBinary(b);
    cout<<b<<endl;
    
    //unset msb upto ith bit
    i = 3;
    b = n & 1<<(i+1)-1 ;  //~(100000-1 is 011111) is 100000
    PrintBinary(b);
    cout<<b;


    //power of 2
    n = 16;
    if(n & n-1) cout<<"Not power of 2"<<endl; //and should be zero bcoz 2^n is 0001000 and 2^n-1 is 0000111
    else cout<<"Power of 2"<<endl;
}