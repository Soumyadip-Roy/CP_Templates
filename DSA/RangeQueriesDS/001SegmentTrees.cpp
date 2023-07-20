#include <bits/stdc++.h>
using namespace std;

class segTree{
    public:
        vector<int> seg;
        segTree(int n){
            seg.resize(4*n+1);
        }

        void build(int ind, int low, int high, int a[])
        {
            if (low == high) //leaf node
            {
                seg[ind] = a[low];
                return;
            }

            int mid = (low + high) / 2;
            build(2 * ind + 1, low, mid, a);
            build(2 * ind + 2, mid + 1, high, a);
            
            seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        }

        int query(int ind, int low, int high, int l, int r)
        {

            if (r < low or high < l)
                return INT_MAX; // no overlap

            if (low >= l and high <= r)
                return seg[ind]; // complete overlap

            // partial overplap
            int mid = (low + high) / 2;

            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1, high, l, r);

            return min(left, right);
        }

        void update(int ind, int low, int high, int i, int val)
        {
            if (low == high)
            {
                seg[ind] = val;
                return;
            }

            int mid = (low + high) / 2;
            if (i <= mid)
                update(2 * ind + 1, low, mid, i, val);
            else
                update(2 * ind + 2, mid+1, high, i, val);

            seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        }
};


int main()
{   
    int n,m;cin>>n>>m;
    int a1[n]={0},a2[m]={0};

    for (int i = 0; i < n; i++)
    {
        cin>>a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>a2[i];
    }

    segTree st1(n);
    st1.build(0,0,n-1,a1);

    segTree st2(m);
    st2.build(0,0,m-1,a2);

    int q;cin>>q;
    while(q--){
        int t;cin>>t;
        if(t==1){
            int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
            cout<<min(st1.query(0,0,n-1,l1,r1),st2.query(0,0,m-1,l2,r2))<<endl;
        }
        else{
            int arrNo;cin>>arrNo;
            int i,val;cin>>i>>val;
            if(arrNo==1){
                st1.update(0,0,n-1,i,val);
                a1[i]=val;
            }
            else if(arrNo==2){
                st2.update(0,0,m-1,i,val);
                a2[i]=val;
            }
        }
    }
}
