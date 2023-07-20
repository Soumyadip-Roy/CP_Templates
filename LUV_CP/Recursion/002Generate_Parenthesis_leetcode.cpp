#include<bits/stdc++.h>
using namespace std;

vector<string> valid;

void generate (string &s , int open , int cls){
    cout<<s<<endl;
    if(open==0 and cls==0){
        valid.push_back(s);
        return;
    }
    if(open>0){
        s.push_back('(');
        generate(s,open-1,cls);
        s.pop_back(); //backtracking
    }
    if(cls>0 and open<cls){
        s.push_back(')');
        generate(s,open,cls-1);
        s.pop_back(); //backtracking
    }
}

int main(){
    string s = "";
    int n; cin>>n;
    generate(s,n,n);
    return 0;
}