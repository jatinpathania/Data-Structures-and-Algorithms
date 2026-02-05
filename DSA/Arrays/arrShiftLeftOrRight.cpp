#include<bits/stdc++.h>
using namespace std;

// move all eles <= x to left and other to right
// optimal sol
void shiftLeftOrRight(vector<int> arr, int x){
    int j=0;
    for(int i=0; i< arr.size() ;i++){
        if(arr[i] <=x){
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
}

// better sol
// void shiftLeftOrRight(vector<int> arr, int x){
//     int n= arr.size();
//     vector<int> ans(n);
//     int left=0;
//     int right= n-1;
//     for(int i=0; i<n ;i++){
//         if(arr[i] < x) ans[left++]= arr[i];
//         else ans[right--] = arr[i];
//     }

//     for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
// }

int main(){
    vector<int> arr= {7,2,9,3,1,8,4};
    int x=6;
    shiftLeftOrRight(arr, x);
}