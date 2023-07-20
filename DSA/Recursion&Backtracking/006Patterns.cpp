#include<bits/stdc++.h>
using namespace std;

// 1. print all subsequences whose sum is k 

// 2. print any subsequence whose sum is k using functional rec and not any global variable
    
    //  IMPORTANT technique to only print one answer -

    // bool f()
    // {
    //  base case
    //          {
    //          cond satisfied return true
    //          else return false
    //          }       

    // if ( f()==true ) return true;
    // return false 
    //
    // }

// a = {1,2,1}
// k = 2;
// draw rec tree to understand 


// 3. count the subsequences with sum = k
// technique to count -

    // int f()
    // {
    //  base case
    //          {
    //          cond satisfied return 1
    //          else return 0
    //          }       

    // l = f() 
    // r = f()
    // return l + r  
    // }

    //note - here we make two recursion calls only but if we need to make multiple recursion calls we can use a for loop


bool subseqSum(int i,vector<int> v,int sum,int a[],int n,int k){
    if(i==n){
        //cond satisfied
        if(sum==k){
            for (auto x : v)cout<<x<<" ";
                cout<<endl;
            return true;
        }
        //not satisfied
       else return false;
    }

    v.push_back(a[i]);
    sum+=a[i];
    if(subseqSum(i+1,v,sum,a,n,k) == true) {
        return true;
    };
    v.pop_back();
    sum-=a[i];
    if(subseqSum(i+1,v,sum,a,n,k) == true) {
        return true;
    };

    return false;
}


int countSubseq(int i,int sum,int a[],int n,int k){
    if(i==n){
        //second base case 
        //strictly for + ve elements
        if(k>sum) return 0;
        //cond satisfied
        if(sum==k){
            return 1;
        }
        //not satisfied
        else return 0;
    }
    sum+=a[i];
    int l = countSubseq(i+1,sum,a,n,k);
    sum-=a[i];
    int r = countSubseq(i+1,sum,a,n,k);
    return r+l;
}

//time coplexity = O(2^n)

int main(){
    //
    
    int a[] = {3,1,2,1,1};
    int n = 5;

    int k = 4;
    int sum = 0;

    vector<int> v={};
    
    subseqSum(0,v,0,a,n,k);
    cout<<countSubseq(0,0,a,n,k);

    
}
