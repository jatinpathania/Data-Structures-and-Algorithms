#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int l, int r){
    int j=0;
    int x= arr[r];
    for(int i=l ;i<=r ;i++){
        if(arr[i] <=x){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j-1;
}

void qs(vector<int>& arr, int low, int high){
    if(low<high){
        int pIndex= partition(arr, low, high);
        qs(arr, low, pIndex-1);
        qs(arr, pIndex+1, high);
    } 
}

void quickSort(vector<int>& arr,int n){
    qs(arr, 0 , n-1);
}

int main(){
    int n;
    cout<<"Enter the no of elements of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    quickSort(arr,n);
    for(int i=0; i<n ;i++) cout<<arr[i]<<" ";
    return 0;
}