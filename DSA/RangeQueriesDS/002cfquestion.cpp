//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

//https://codeforces.com/contest/339/problem/D

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

void build(int ind,int low ,int high, vector<int> &v ,int seg[], int flag){
    if(low==high){
        seg[ind]=v[low];
        return;
    }
    int mid = (low+high)/2;
    build(2 * ind + 1, low, mid, v ,seg,!flag);
    build(2 * ind + 2, mid + 1, high, v ,seg, !flag);

    if(flag) seg[ind] = (seg[2*ind+1] | seg[2*ind+2]);
    else seg[ind] = (seg[2*ind+1] ^ seg[2*ind+2]);
}

void update(int ind,int low,int high ,int seg[],int flag,int i ,int val){
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid = (low+high)/2;
    if(i<=mid) update(2*ind+1,low,mid, seg,!flag,i,val);
    else update(2*ind+2,mid+1,high, seg,!flag,i,val);

    if(flag) seg[ind] = (seg[2*ind+1] | seg[2*ind+2]);
    else seg[ind] = (seg[2*ind+1] ^ seg[2*ind+2]);
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
        int n,m;cin>>n>>m;
        int k = pow(2,n);
        vector<int> v(k);
        for (int i = 0; i < k; i++)
        {
            cin>>v[i];
        }
        int seg[4*k]={0};

        if(n%2)build(0,0,k-1,v,seg,1);
        else build(0,0,k-1,v,seg,0);

        while (m--)
        {
            int i,val;
            cin>>i>>val;
            i--;
            if(n%2)update(0,0,k-1,seg,1,i,val);
            else update(0,0,k-1,seg,0,i,val);

            cout<<seg[0]<<"\n";
        }
        
    }
}