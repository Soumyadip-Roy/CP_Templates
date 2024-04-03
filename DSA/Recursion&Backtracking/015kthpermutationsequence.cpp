#include <bits/stdc++.h>
using namespace std;
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

    string getPermutation(int n,int k){
        k--;
        vector<int> num(n);
        int f=1;
        for(int i=1;i<n;i++){
            f*=i;
            num[i-1]=i;
        }
        num[n-1]=n;
        
        string s;
        while(num.size()>0){
            s.push_back('0'+ num[k/f]);
            num.erase(num.begin()+k/f);
            k=k%f;
            if(num.size())f/=num.size();
        }
        return s;
    }

int main()
{   

}
