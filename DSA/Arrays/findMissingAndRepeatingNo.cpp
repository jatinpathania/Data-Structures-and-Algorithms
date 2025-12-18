#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};

    Solution sol;
    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    return 0;
}
