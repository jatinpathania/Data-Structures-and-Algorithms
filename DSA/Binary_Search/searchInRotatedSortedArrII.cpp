#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>& arr, int k){
    int low=0, high= arr.size()-1;
        while(low<= high){
            int mid= low+ (high-low)/2;
            if(arr[mid] == k) return true;
            if(arr[low]== arr[mid] && arr[mid]== arr[high]){
                low++;
                high--;
                continue;
            }
            if(arr[low] <= arr[mid]){                                             // check if left is sorted
                if(arr[low] <= k && k <= arr[mid]){
                    high= mid-1;
                }else{
                    low= mid+1;
                }
            }
            else{                                                                   //check if right is sorted
                if(arr[mid] <= k && k <= arr[high]){
                    low= mid+1;
                }
                else{
                    high= mid-1;
                }
            }
        }
        return false;
}

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (ans)
        cout << "k is present in the array.\n";
    else
        cout << "k is not present.\n";
    return 0;
}
