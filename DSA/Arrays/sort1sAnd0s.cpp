#include <bits/stdc++.h>
using namespace std;

//Optimal sol (Dutch National Flag Algorithm)
void sortArray(vector<int>& arr, int n){
    int low= 0;
    int mid=0;
    int high= n-1;
    while(mid <= high){
        if(arr[mid]==0 ){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) mid++;
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}



//better sol
// void sortArray(vector<int>& arr, int n){
//     int count0=0, count1=0, count2=0;
//     for(int num: arr){
//         if(num== 0) count0++;
//         else if(num== 1) count1++;
//         else count2++;
//     }
//     for(int i=0; i< count0 ;i++) arr[i]= 0;
//     for(int i= count0; i< count0+count1; i++) arr[i]=1;
//     for(int i=count0+count1 ; i<n; i++) arr[i]= 2;
// }

int main(){
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
