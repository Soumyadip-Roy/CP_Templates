#include <bits/stdc++.h>
using namespace std;

//https://www.spoj.com/problems/INVCNT/

#define int long long

class segTree{
    public:
        vector<int> seg;
        segTree(int n){
            seg.resize(4*n+1,0);
        }

        void build(int ind, int low, int high, int a[])
        {
            if (low == high)
            {
                seg[ind] = a[low];
                return;
            }

            int mid = (low + high) / 2;
            build(2 * ind + 1, low, mid, a);
            build(2 * ind + 2, mid + 1, high, a);
            seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
        }

        int query(int ind, int low, int high, int l, int r)
        {
            // lr low high lr
            if (r < low or high < l)
                return 0; // no overlap
            // l low high r
            if (low >= l and high <= r)
                return seg[ind]; // complete overlap

            // partial overplap
            int mid = (low + high) / 2;

            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1, high, l, r);

            return left + right;
        }

        void update(int ind, int low, int high, int i, int val)
        {
            if (low == high)
            {
                seg[ind] += val;
                return;
            }

            int mid = (low + high) / 2;
            if (i <= mid)
                update(2 * ind + 1, low, mid, i, val);
            else
                update(2 * ind + 2, mid+1, high, i, val);
            seg[ind] =  seg[2 * ind + 1] + seg[2 * ind + 2];
        }
};

signed main()
{  
    int t;cin>>t;
    while(t--){

    
    int n;cin>>n;
    vector<int> v(n);
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        mx = max(mx,v[i]);
    }

    mx+=1;
    
    int freq[mx]={0};

    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }
    segTree seg(mx);
    seg.build(0,0,mx-1,freq);
   
    int ct = 0;

    for (int i = 0; i < n; i++)
    {   
        freq[v[i]]--;
        ct+=seg.query(0,0,mx-1,0,v[i]-1);
        seg.update(0,0,mx,v[i],-1);
    }

    cout<<ct<<endl;
    }
}

