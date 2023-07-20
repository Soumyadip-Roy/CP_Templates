#include <bits/stdc++.h>
using namespace std;

// upd the node when you visit it
// once you update propagate the node downwards

// Range Update Rules  - l,r --> +val

// Traverse in  seg tree , update prev remaining updates
// check if the node completely overlaps with l,r
// update the node
// lazy propagate downwards and return
// partial overlap
// left
// right
// node = left+right
// no overlap
// return

class segTree
{
public:
    vector<int> seg, lazy;

    segTree(int n)
    {
        seg.resize(4 * n + 1,0);
        lazy.resize(4 * n + 1,0);
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

int RangeQuery(int ind, int low, int high, int l, int r)
    {
        // update previous remaining updates
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propagate the lazy update downwards 
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        if (r < low or high < l)
            return 0; 

        // complete overlap
        if (low >= l and high <= r)
            return seg[ind]; 

        // partial overplap
        int mid = (low + high) >> 1;
        int left = RangeQuery(2 * ind + 1, low, mid, l, r);
        int right = RangeQuery(2 * ind + 2, mid + 1, high, l, r);

        return left+right;
    }


    void RangeUpdate(int ind, int low, int high, int l, int r, int val)
    {
        // update previous remaining updates
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propagate the lazy update downwards
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        if (r < low or l > high)
            return;

        // complete overlap
        if (low >= l and high <= r)
        {
            seg[ind] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        // partial overlap
        int mid = (low + high) >> 1;
        RangeUpdate(2 * ind + 1, low, mid, l, r, val);
        RangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    //cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        int v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        segTree seg(n);
        seg.build(0,0,n-1,v);
        
        int q;cin>>q;
        while(q--){
            int t;cin>>t;

            int l, r, x;
            if (t == 1)
            {
                cin >> l >> r;
                cout << seg.RangeQuery(0, 0, n - 1, l, r) << endl;
            }
            else
            {
                cin >> l >> r >> x;
                seg.RangeUpdate(0, 0, n - 1, l, r, x);
            }
        }


    }
}
