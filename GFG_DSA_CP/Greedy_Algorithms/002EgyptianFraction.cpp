#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

//Egyptian Fraction

void egyptianFraction(int nr ,int dr){
    if(!dr or !nr)return;
    //if nr divides dr
    if(dr%nr==0){
        cout<<"1/"<<dr/nr;
        return;
    }
    //if dr divides nr;
    if(nr%dr==0){
        cout<<nr/dr;
        return;
    }
    //if nr > dr
    if(nr>dr){
        cout<<nr/dr<<" + ";
        egyptianFraction(nr%dr,dr);
        return;
    }

    int n = dr/nr + 1;
    cout << "1/" << n << " + ";
    // nr|dr - 1|n = nr*n-dr|dr*n; 
    nr = nr*n-dr;
    dr = dr*n;
    egyptianFraction(nr,dr);
}

signed main(){
    
    // egyptianFraction(8,4);
    // cout<<endl;
    // egyptianFraction(4,8);
    // cout<<endl;
    // egyptianFraction(11,4);
    // cout<<endl;
    // egyptianFraction(3,16);
    // cout<<endl;
    return 0;
}