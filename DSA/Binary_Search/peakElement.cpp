#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findPeakElement(vector<int>& nums){
        int n= nums.size();
        if(n==1) return 0; 
        if(nums[0] >nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low= 1, high= n-2;        //search space trimmed
        while(low<= high){
            int mid= low+ (high-low)/2;
            if(nums[mid-1] < nums[mid] && nums[mid]> nums[mid+1]) return mid;
            else if(nums[mid] > nums[mid-1]){           //means left is sorted, so eliminate it, peak's on right one
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution obj;
    cout <<"The peak element in the array is: " <<obj.findPeakElement(nums) << endl;
    return 0;
}