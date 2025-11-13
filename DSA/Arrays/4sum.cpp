#include <bits/stdc++.h>
using namespace std;

//optimal approach- O(n²xn) ~ O(n³)
vector<vector<int>> fourSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n= nums.size();
    for(int i=0; i<n ;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<n ;j++){
            if(j> i+1 && nums[j] == nums[j-1]) continue;
            int k= j+1;
            int l= n-1;
            while(k<l){
                long long sum= nums[i];
                sum+= nums[j];
                sum+= nums[k];           //diff for long long typecasting
                sum+= nums[l];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    vector<int> temp= {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
