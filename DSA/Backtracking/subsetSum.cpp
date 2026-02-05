#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void func(int ind,int sum,vector<int>& arr,int N, vector<int>& sumSubset){
        if(ind== N){
            sumSubset.push_back(sum);
            return;
        }
        func(ind+1,sum+arr[ind],arr,N,sumSubset);
        func(ind+1,sum,arr,N,sumSubset);
    }
    vector<int> subsetSum(vector<int>&arr,int N){
        vector<int> sumSubset;
        func(0,0,arr,N,sumSubset);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }
};

int main(){
    vector<int>arr = {3,1,2};
    int N= arr.size();
    Solution sol;
    vector<int> ans= sol.subsetSum(arr,N);
    for(int sum: ans){
        cout<<sum<<" ";
    }
    return 0;
}
