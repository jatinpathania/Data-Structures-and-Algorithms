#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    int mmin= 0;
    for(int i=0 ;i <= n-2 ; i++){
        mmin= i;
        for(int j= i ; j<= n-1 ; j++){
            if(arr[j] < arr[mmin]){
                mmin= j;
            }
        }
        //swap
        int temp= arr[i];
        arr[i]= arr[mmin];
        arr[mmin]= temp;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++) cin>> arr[i];
    selectionSort(arr,n);
    //print
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}