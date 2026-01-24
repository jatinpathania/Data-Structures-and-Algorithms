#include <bits/stdc++.h>
using namespace std;

//Recursive code
class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if(low> high) return -1;
        int mid= low+ (high- low)/2;
        if(target== nums[mid]) return mid;
        else if(target > nums[mid]) return binarySearch(nums, mid+1, high, target);
        return binarySearch(nums, low, mid-1, target);
    }

    int search(vector<int>& nums, int target) {
        int n= nums.size();
        return binarySearch(nums, 0, n-1, target);
    }
};

// Iterative code
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n= nums.size();
//         int low=0, high= n-1;
//         while(low<=high){
//             int mid = (low+high)/2;
//             if(nums[mid] == target) return mid;
//             else if(target> nums[mid]){
//                 low= mid+1;
//             }
//             else{
//                 high= mid-1;
//             }
//         } 
//         return -1;
//     }
// };

int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    Solution obj;
    int ind = obj.search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;
    return 0;
}

