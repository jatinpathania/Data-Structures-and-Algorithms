#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(logn)
// Space Complexity: O(1) 
// find the smallest element greater than equal to given number
class LowerBoundFinder {
public:
    int lowerBound(vector<int> arr, int n, int x){
        int low=0, high= n-1;
        int ans= n;
        while(low <= high){
            int mid= low+ (high-low)/2;
            if(arr[mid] >= x){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();
    int x = 9;
    LowerBoundFinder finder;
    int ind = finder.lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

//Shortcut for cpp-  lower_bound(arr.begin(), arr.end(), x)- arr.begin();