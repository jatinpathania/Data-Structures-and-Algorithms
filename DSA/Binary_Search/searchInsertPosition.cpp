#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(logN)
// Space Complexity: O(1)
class BinarySearchInsert {
public:
    int searchInsert(vector<int>& arr, int x){
        int n= arr.size();
        int low=0, high=n-1;
        int ans=n;
        while(low <= high){
            int mid= low+ (high-low)/2;
            if(arr[mid] >=x){
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

int main(){
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    BinarySearchInsert obj;
    int index = obj.searchInsert(arr,x);
    cout << "The index is: " << index << endl;
    return 0;
}
