#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k){
    unordered_map<int,int> mpp;
    mpp[0]=1;      //most important for handling case..where subarray itself becomes equal to k 
    int count=0;
    int preSum=0;
    for(int i=0; i<arr.size() ;i++){
        preSum+= arr[i];
        int rem= preSum- k;
        count+= mpp[rem];
        mpp[preSum]+= 1;
    }
    return count;
}  
//time complexity
//for unordered_map .. its O(n)and O(1) 
//but for ordered .. its O(n) and O(log N)

int main(){
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}