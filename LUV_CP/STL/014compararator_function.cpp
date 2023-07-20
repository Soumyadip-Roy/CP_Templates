#include <bits/stdc++.h>
using namespace std;

/*bool should_i_swap(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first){
        if(a.first > b.first) return true
        else return false;
    }
    else if(a.second > b.second) return true;
        else return false ;
}*/

/*the behaviour of comparator fn is opposite ie it swaps when false is returned
bool should_i_swap(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first){
        if(a.first > b.first) return false; //return false for cmp fn
        else return true;
    }
    else if(a.second > b.second) return true;
        else return false;
}*/

/*easier method for cmp fn - return what ever you need */
bool should_i_swap(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first) return a.first < b.first;
    else return b.second < a.second;
}
int main()
{

    int n;
    cin >> n;
    vector< pair<int,int> > a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }

    sort(a.begin(), a.end(), should_i_swap);

    /*for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (should_i_swap(a[i], a[j]))
                swap(a[i], a[j]);
        }
    }*/

    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " "<< a[i].second <<endl;
    }

    return 0;
}