#include <bits/stdc++.h>
using namespace std;

//Optimal sol O(2N) for positives only
int getLongestSubarray(vector<int>& a, long long k){
    int left=0, right=0;
    long long sum=0;
    int maxLength=0;
    int n= a.size();
    while(right < n){
        while(left <= right && sum>k){
            sum-= a[left];
            left++;
        }
        if(sum == k){
            maxLength= max(maxLength, right - left+1);
        }
        right++;
        if(right< n) sum+= a[right];
    }
    return maxLength;
}


//Better solution ( for pos and negatives both)
// int getLongestSubarray(vector<int>& a, long long k){
//     map<long long ,int> preSum;
//     long long sum=0;
//     int maxLength=0;
//     for(int i= 0; i<a.size(); i++){
//         sum+= a[i];
//         if(sum == k){
//             maxLength= max(maxLength, i+1);
//         }

//         long long rem= sum- k;
//         if(preSum.find(rem)!= preSum.end()){
//             int len= i- preSum[rem];
//             maxLength= max(maxLength, len);
//         }
//         //for zeroes
//         if(preSum.find(sum)== preSum.end()){
//             preSum[sum]= i;
//         }
//     }
//     return maxLength;
// }

int main(){
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
