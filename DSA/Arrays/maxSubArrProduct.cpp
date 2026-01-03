#include <bits/stdc++.h>
using namespace std;

//Time complexity- O(N)
//Space complexity- O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prefix=1;
        int sufix=1;
        int ans= INT_MIN;
        for(int i=0; i<n; i++){
            if(prefix == 0) prefix=1;
            if(sufix == 0) sufix=1;
            prefix*= nums[i];
            sufix*= nums[n-i-1];
            ans= max(ans, max(prefix, sufix));
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution sol;
    cout << sol.maxProduct(nums);
    return 0;
}
