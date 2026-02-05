#include<bits/stdc++.h>
using namespace std;
void countSubsequences(int index, vector<int>& nums, int sum, int k, int& count){
    if(index==nums.size()){
        if(sum==k) count++;
        return;
    }
    countSubsequences(index+1,nums,sum+nums[index],k,count);
    countSubsequences(index+1,nums,sum,k,count);
}
int countSubsequencesWithSumK(vector<int>& nums, int k){
    int count=0;
    countSubsequences(0,nums,0,k,count);
    return count;
}
int main(){
    vector<int>nums = {1,2,1};
    int k =2;
    int result =countSubsequencesWithSumK(nums,k);
    cout << "Total subsequences with sum "<<k<<" = "<<result<<endl;
    return 0;
}
