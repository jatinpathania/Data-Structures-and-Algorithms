#include <bits/stdc++.h>
using namespace std;

// Optimal sol I  (Using mathematical way)
// Time complexity- O(N), Space complexity- O(1)
// class Solution {
// public: 
//     vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
//         long long n= nums.size();
//         // S- SN
//         // S²- S²N
//         long long SN= (n*(n+1))/2;
//         long long S2N= (n*(n+1)*(2*n+1))/6;
//         long long S=0, S2=0;
//         for(int i=0; i<n; i++){
//             S+= nums[i];
//             S2+= (long long)nums[i]* (long long)nums[i];
//         }
//         long long val1= S- SN;    // x-y
//         long long val2= S2- S2N;
//         val2= val2/val1;   // x+y
//         long long x= (val1+ val2)/2;         // repeting
//         long long y= x- val1;               //missing
//         return {(int)x, (int)y};
//     }
// };

// Optimal sol II  (Using Xor way)
// Time complexity- O(N), Space complexity- O(1)
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        int n= nums.size();
        int xr=0;
        // xored array eles and nos till n
        for(int i=0; i<n; i++){
            xr= xr^ nums[i];
            xr= xr^ (i+1);
        }
        
        // finding diff bit
        int bitNo= 0;
        while(1){
            if( (xr & (1<< bitNo))!=0 ){
                break;
            }
            bitNo++;
        }

        // placing in 0 and 1 club and xoring immediately to save steps
        int zero=0;
        int one=0;
        for(int i=0; i<n ;i++){
            // part of 1 club
            if( (nums[i]& (1<< bitNo)) !=0 ){
                one= one^ nums[i];
            }
            // part of 0 club
            else{
                zero= zero^ nums[i];
            }
        }
        // do same thing for nos till n
        for(int i=1; i<=n ;i++){
            if( (i & (1<< bitNo)) !=0 ){
                one= one^ i;
            }
            // part of 0 club
            else{
                zero= zero^ i;
            }
        }

        // confirming the numbers
        int cnt=0;
        for(int i=0; i<n ;i++){
            if( nums[i] == zero) cnt++;  // zero club contained repeating one
        }
        if(cnt == 2) return {zero, one};
        else return {one, zero};
    }
};

// Hashmap sol- Time complexity- O(2N), Space complexity- O(N)
// class Solution {
// public:
//     vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
//         int n= nums.size();
//         int hash[n+1]= {0};
//         for(int i=0; i<n; i++){
//             hash[nums[i]]++;
//         } 
//         int repeating=-1, missing=-1;
//         for(int i=1; i<=n; i++){         // coz no start from 1 to n
//             if(hash[i]== 2) repeating= i;
//             else if(hash[i]== 0) missing= i; 

//             if(repeating!=-1 && missing!=-1){
//                 break;
//             }
//         }
//         return {repeating, missing};
//     }
// };

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};

    Solution sol;
    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    return 0;
}
