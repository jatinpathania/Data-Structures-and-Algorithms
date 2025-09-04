#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums){
        int n=nums.size();
        int count=0;
        for(int i=0; i<n ; i++){
            if(nums[i] > nums[(i+1)% n]){
                count++;
            }
        }
        return count<=1;
    }
}

int main() {
    Solution sol;

    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "[3,4,5,1,2] -> " << (sol.check(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {2, 1, 3, 4};
    cout << "[2,1,3,4] -> " << (sol.check(nums2) ? "true" : "false") << endl;

    vector<int> nums3 = {1, 2, 3};
    cout << "[1,2,3] -> " << (sol.check(nums3) ? "true" : "false") << endl;

    vector<int> nums4 = {1, 1, 1};
    cout << "[1,1,1] -> " << (sol.check(nums4) ? "true" : "false") << endl;

    return 0;
}
