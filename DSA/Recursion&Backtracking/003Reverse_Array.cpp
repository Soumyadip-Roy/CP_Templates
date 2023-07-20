#include<bits/stdc++.h>
using namespace std;

// reverse an array

int arr[10]={1,2,3,4,5,6,7,8,9,10};
int n = 10;

//using two-pointers

void reverse(int l,int r){
    if(r-l<1)return;
    swap(arr[l],arr[r]);
    reverse(l+1,r-1);
}

//single varible

void reverse2(int i){
    if(i>=n/2)return;
    swap(arr[i],arr[n-i-1]);
    reverse2(i+1);
}

//is Palindrome
int isPalindrome(int i ,string s,int k){
    if(i>=k/2)return 1;
    if(s[i]!=s[k-i-1]){
        return 0;
    }
    return 1 and isPalindrome(i+1,s,k);
}

// time complexity = O(n/2)
// space complexity = O(n/2)

int main(){
    reverse(0,9);
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
    reverse2(0);
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;

    isPalindrome(0,"madam",5)?cout<<"YES":cout<<"NO";
}