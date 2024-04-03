#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++) {
        if (S[i] != S[S.length() - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// https://leetcode.com/problems/palindrome-partitioning/

set<vector<string>> ans;
vector<string> v;

void partition(string s,int idx){
    if(idx==s.length()){
        ans.insert(v);
        return;
    }

    for(int i=idx;i<s.length();i++){
        string str = s.substr(idx,i-idx+1);
        if(isPalindrome(str)){
            v.push_back(str);
            partition(s,i+1);
            v.pop_back();
        }
    }
}

int main(){
    string s;cin>>s;
    partition(s,0);

    cout<<ans.size();
    for (auto x:ans)
    {
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}