#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n= arr.size();
        unordered_map<int,int> mp;
        int sum = 0, maxLen = 0;
        mp[0]= -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) sum += -1;
            else sum += 1;

            if(mp.find(sum)!= mp.end()) {
                maxLen = max(maxLen, i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {0, 1};
    cout << "Test 1: [0, 1] -> " << sol.findMaxLength(arr1) << endl;
    
    vector<int> arr2 = {0, 1, 0};
    cout << "Test 2: [0, 1, 0] -> " << sol.findMaxLength(arr2) << endl;
    
    vector<int> arr3 = {0, 0, 1, 0, 0, 0, 1, 1};
    cout << "Test 3: [0, 0, 1, 0, 0, 0, 1, 1] -> " << sol.findMaxLength(arr3) << endl;
    
    vector<int> arr4 = {1, 1, 1, 1};
    cout << "Test 4: [1, 1, 1, 1] -> " << sol.findMaxLength(arr4) << endl;
    
    vector<int> arr5 = {0, 0, 0, 1, 1, 1};
    cout << "Test 5: [0, 0, 0, 1, 1, 1] -> " << sol.findMaxLength(arr5) << endl;
    
    return 0;
}
