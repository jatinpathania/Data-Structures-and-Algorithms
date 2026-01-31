#include <bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int> &arr){
    int low= 0, high= arr.size()-1;
    int ans= INT_MAX;
    int index=-1;
    while(low <= high){
        int mid= low+ (high- low)/2;
        
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index= low;
                ans= arr[low];
            }
            break;
        }

        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index= low;
                ans= arr[low];
            }
            low= mid+1;
        }
        else{
            high= mid-1;    
            if(arr[mid] < ans){
                index= mid;
                ans= arr[mid];
            }
        }
    }
    return index;
}

// Shorter code
// int findRotationCount(vector<int> &arr){
//     int low= 0, high= arr.size()-1;
//     int ans= INT_MAX;
//     while(low < high){
//         int mid= low+ (high- low)/2;
//         if(arr[mid] > arr[high]){        // finding unsorted part
//             low= mid+1;
//         }
//         else{
//             high= mid;
//         }
//     }
//     return low;
// }

int main() {
    vector<int> arr = {3, 4, 5, 1, 2};
    int rotations = findRotationCount(arr);
    cout << rotations << endl;
    return 0;
}
