#include <bits/stdc++.h>
using namespace std;

int ct=0;
void merge(int low,int mid,int high,int arr[]){
    vector<int> temp;
    int l=low;
    int r=mid+1;
    while(l<=mid and r<=high){
        if(arr[l]<=arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else{
            temp.push_back(arr[r]);
            r++;
            ct+=(mid-l+1);
        }
    }
    while(l<=mid ){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high ){
        temp.push_back(arr[r]);
        r++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(int low,int high,int arr[]){
    if(low<high){
        int mid=(high+low)/2;
        mergeSort(low,mid,arr);
        mergeSort(mid+1,high,arr);
        merge(low,mid,high,arr);
    }
}

int main()
{   
    int arr[3]={3,2,1};
     for (int i = 0; i < 3; i++)
    {
        cout<<arr[i];
    }
    mergeSort(0,2,arr);
    for (int i = 0; i < 3; i++)
    {
        cout<<arr[i];
    }
    
}
