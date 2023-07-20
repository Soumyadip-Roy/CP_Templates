#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

// 39. combination sum leetcode 

//logic 2 for array problems - loop every element

//draw recursion tree for better understanding
vector<vector<int>> ans;

void subseq(int ind,vector<int> v,vector<int> a,int n,int t){
        if(t==0){
            ans.push_back(v);
            return;
        }

        for (int i = ind; i < n; i++)
        {   
            // skip if the curr element is same as the prev element
            if(i>ind and a[i]==a[i-1]) continue;
            // target must be less than curr element (since list is sorted all elements to the right will also be > than target so break the loop )
            if(a[i]>t) break;

            //picked
            v.push_back(a[i]);
            // start from the next index  
            subseq(i+1,v,a,n,t-a[i]);
            v.pop_back();
        }
        
    }

int main()
{
    int n = 5;
    vector<int> a = {1,2,3,4,1};
    int t = 4;
    vector<int> v; 

    sort(a.begin(),a.end());
    
    subseq(0,v,a,n,t);
    cout<<ans.size();
    for(auto x: ans){
        for(auto p : x){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}
