#include <iostream>
#include <vector>
using namespace std;
bool hasSubsequenceSum(int index, int currentSum,const vector<int>& nums, int k){
    if(index == nums.size()){
        return currentSum == k;
    }
    if(hasSubsequenceSum(index +1, currentSum +nums[index],nums,k)) {
        return true;
    }
    if(hasSubsequenceSum(index+ 1, currentSum, nums, k)) {
        return true;
    }

    return false;
}
int main() {
    vector<int> nums ={1,2,3,4};
    int k =6;
    if(hasSubsequenceSum(0,0,nums,k)) {
        cout <<"Yes, a subsequence with sum "<< k<<" exists.\n";
    } else {
        cout<<"No, such subsequence does not exist.\n";
    }
    return 0;
}
