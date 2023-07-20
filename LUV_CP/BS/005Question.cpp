#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long n, cows;
long long a[N];

bool canPlaceCows(int min_dist)
{
    int last = -1;
    int cows_ct = cows;
    for (int i = 0; i < n; i++)
    {
        if(a[i]-last >= min_dist || last ==-1){
            cows_ct--;
            last = a[i];
        }
    }
    return (cows_ct==0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> cows;
        for (int i = 0; i < n; i++)cin >> a[i];
        sort(a,a+n);

        int lo = 0, hi = 1e9, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (canPlaceCows(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (canPlaceCows(hi))
            cout << hi;
        else
            cout << lo;

        cout<<endl;
    }
    return 0;
}