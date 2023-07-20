#include<bits/stdc++.h>
using namespace std;

double acc = 1e-6; //upto x-1 accuracy

double multiply(double mid , int n){
    double m = 1;
    for (int i = 0; i < n; i++)m*=mid;
        cout<< mid; 
        return mid;
}

void Sqrt(double x , int n){
    double lo = 1, hi = x, mid;
    while(hi-lo>acc){
        mid = (hi+lo)/2;
        if(multiply(mid,n)<x) lo=mid;
        else hi=mid;
    } 
    cout<<setprecision(10)<<lo<<endl<<hi<<endl;
}

int main(){
   
    double x ;
    int n;
    cin>>x>>n;

    Sqrt(x , n);
    cout<<pow(x,1.0/n);

    return 0;
}