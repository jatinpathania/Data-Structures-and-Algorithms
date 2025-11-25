#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Type-I 
    // If asked in interview , no extra space allowed for array 1 like {1,2,3}
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1,int ind2){
        if( nums1[ind1] > nums2[ind2] ){
            swap(nums1[ind1], nums2[ind2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len= (m+n);
        int gap= (len)/2 +(len%2);
        while(gap >0){
            int left= 0;
            int right= left+ gap;
            while(right < len){
                // arr1 and arr2
                if(left<m && right>= m){
                    swapIfGreater(nums1, nums2, left , right -m);
                }
                // arr2 and arr2
                else if(left >=m){
                    swapIfGreater(nums2, nums2,left -m , right-m );
                }
                // arr1 and arr1
                else{
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap= (gap)/2 +(gap%2);
        }

        for(int i=0; i<n ;i++){
            nums1[m+i]= nums2[i];
        }
    }


    // Type -II 
    // For leetcode style problems where extra space in array1 is allowed like {1,2,3,0,0,0,0}

    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int i= m-1;
    //     int j= n-1;
    //     int k= m+n-1;
    //     while(i>=0 && j>=0){
    //         if(nums1[i] > nums2[j]){
    //             nums1[k--] = nums1[i--];
    //         }
    //         else{
    //             nums1[k--]= nums2[j--];
    //         }
    //     }

    //     while( j>=0 ) nums1[k--] = nums2[j--];
    // }


    // Type - III
    // If problem states to just sort eles in their proper way but not put all in one array
    // Optimal O(min(m,n))+O(nlogn)+O(mlogm)

    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int left= m-1;
    //     int right= 0;
    //     while(left>=0 && right<n){
    //         if(nums1[left]> nums2[right]){
    //             swap(nums1[left], nums2[right]);
    //             left--;
    //             right++;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     sort(nums1.begin(), nums1.end());
    //     sort(nums2.begin(), nums2.end());
    // }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;
    Solution().merge(nums1, m, nums2, n);
    for (int num : nums1) cout << num << " ";
    return 0;
}