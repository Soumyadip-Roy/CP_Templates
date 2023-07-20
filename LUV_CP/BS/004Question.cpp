#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
long long n , m;
long long a[N];

bool isHsuff(int h){
    long long sum = 0 ;
    for (int i = 0 ; i < n ; i++){
        if(a[i]-h>=0){sum+=(a[i]-h);}
    }
    return sum>=m;
}

int main()
{
    cin >> n >>m;
    for (int i = 0; i < n; i++)cin>>a[i];

    long long lo = 0, hi = 1e9 , mid;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(isHsuff(mid))lo=mid;
        else hi = mid-1;
    }
    if(isHsuff(hi))cout<<hi;
    else cout<<lo;

return 0;
}