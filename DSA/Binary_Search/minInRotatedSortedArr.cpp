#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //most optimised version
    int findMin(vector<int>& nums){
        int low= 0, high= nums.size()-1;
        int ans= INT_MAX;
        while(low <= high){
            int mid= low+ (high- low)/2;
            //put a check if search space is alredy sorted, then always nums[low]  will be smallest 
            if(nums[low] <= nums[high]){
                ans= min(ans, nums[low]);
                break;
            }

            if(nums[low] <= nums[mid]){
                ans= min(ans, nums[low]);
                low= mid+1;
            }
            else{
                high= mid-1;    
                ans= min(ans, nums[mid]);
            }
        }
        return ans;
    }


    // from sorted part, pick first ele and move low to next of mid, from unsorted part, compare with mid element always
    // int findMin(vector<int>& nums){
    //     int low= 0, high= nums.size()-1;
    //     int ans= INT_MAX;
    //     while(low <= high){
    //         int mid= low+ (high- low)/2;
    //         if(nums[low] <= nums[mid]){
    //             ans= min(ans, nums[low]);
    //             low= mid+1;
    //         }
    //         else{
    //             high= mid-1;    
    //             ans= min(ans, nums[mid]);
    //         }
    //     }
    //     return ans;
    // }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    int result = sol.findMin(nums);
    cout << "Minimum element is " << result << endl;
    return 0;
}
