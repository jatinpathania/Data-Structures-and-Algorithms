#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //optimal approach- O(N log N) and O(N) space
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());
        int n= intervals.size();
        vector<vector<int>> ans;
        for(int i=0 ; i<n; i++){
            if( ans.empty() || intervals[i][0] >ans.back()[1] ){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]= max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }

    // brute force- O(N logn)+ O(2N)
    // vector<vector<int>> merge(vector<vector<int>>& intervals){
    //     sort(intervals.begin(), intervals.end());
    //     int n= intervals.size();
    //     vector<vector<int>> ans;
    //     for(int i=0; i<n; i++){
    //         int start= intervals[i][0];
    //         int end= intervals[i][1];
    //         if( !ans.empty() && end <= ans.back()[1] ) continue;
    //         for(int j= i+1; j<n; j++){
    //             if( intervals[j][1] <= end ){
    //                 end= max(end, intervals[j][1]);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //         ans.push_back({ start, end });
    //     }
    //     return ans;
    // }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = sol.merge(intervals);
    for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}