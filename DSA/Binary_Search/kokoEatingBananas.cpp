#include <bits/stdc++.h>
using namespace std;

//Time complexity-  O(N*log(max(a[])))
class Solution {
public:
    int findMax(vector<int>& arr){
        int maxi= arr[0];
        for(int i=0; i< arr.size(); i++){
            maxi= max(maxi, arr[i]);
        }
        return maxi;
    }
    int findTotalHours(vector<int>& piles, int hourly){
        int totalHours=0;
        for(int i=0; i<piles.size(); i++){
            totalHours += ceil((double)piles[i]/ (double)hourly);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h){
        int low=1, high= findMax(piles);
        while(low<=high){
            int mid= low+(high-low)/2;
            int totalHours= findTotalHours(piles, mid);
            if(totalHours <= h){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return low;     // opposite polarity
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    Solution obj;
    cout << "Minimum eating speed: " << obj.minEatingSpeed(piles, h) << endl;
    return 0;
}
