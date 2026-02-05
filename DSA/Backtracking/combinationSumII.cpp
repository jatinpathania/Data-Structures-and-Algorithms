#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void findCombinations(int ind,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombinations(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombinations(0,target,candidates,ans,ds);
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> candidates ={10,1,2,7,6,1,5};
    int target =8;
    vector<vector<int>>combinations = sol.combinationSum2(candidates, target);
    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
