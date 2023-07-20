#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(), v.end()

//Job Sequence
struct data
{
    char a;
    int d, p;
};

bool comp(data a,data b){return a.p>b.p;}

void jobSeq(vector<data> v){
    sort(all(v),comp);
    int t = 0;
    vector<char> seq;
    for (int i = 0; i < v.size(); i++)
    {
        if(t<v[i].d){
            seq.push_back(v[i].a);
            t++;
        }
    }
    for (int i = 0; i < seq.size(); i++)
    {
        cout<<seq[i]<<" ";
    }
}

signed main()
{
    // vector<data> v = {
    //     { 'a', 2, 100 },
    //     { 'b', 1, 19 },
    //     { 'c', 2, 27 },
    //     { 'd', 1, 25 },
    //     { 'e', 3, 15 }
    // };
    // jobSeq(v);
    return 0;
}