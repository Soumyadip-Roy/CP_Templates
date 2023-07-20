//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

//https://codeforces.com/contest/380/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

class node{
    public:
    int open;
    int close;
    int full;
    node(){}
    node(int o,int c,int f){
        open=o;close=c;full=0;
    }
};

node merge(node left,node right){
    node par;
    par.full=left.full+right.full+min(left.open,right.close);
    par.open=left.open+right.open-min(left.open,right.close);
    par.close=left.close+right.close-min(left.open,right.close);
    return par;
}


void build(int ind,int low ,int high, string &s,node seg[]){
    if(low==high){
        seg[ind].full=0;
        seg[ind].open=s[low]=='(';
        seg[ind].close=s[low]==')';
        return;
    }
    int mid = (low+high)/2;
    build(2 * ind + 1, low, mid, s, seg);
    build(2 * ind + 2, mid + 1, high, s, seg);

    seg[ind] = merge(seg[2*ind+1],seg[2*ind+2]);

}


node query(int ind, int low, int high, int l, int r,node seg[])
    {
        if (r < low or high < l)
            return node(0,0,0); // no overlap
        if (low >= l and high <= r)
            return seg[ind]; // complete overlap

        // partial overplap
        int mid = (low + high) / 2;
        node left = query(2 * ind + 1, low, mid, l, r,seg);
        node right = query(2 * ind + 2, mid + 1, high, l, r,seg);
        return merge(left,right);
    }

signed main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;//cin >> T;
    while (T--)
    {
        string s;cin>>s;
        int n = s.length();
        node seg[4*n];
        build(0,0,n-1,s,seg);
        // for(int i=0;i<3*n ;i++)cout<<seg[i].full<<" ";
        int q;cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;r--;
            node ans = query(0,0,n-1,l,r,seg);
            cout<<2*ans.full<<endl;
        }
    }
}