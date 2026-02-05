#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(N log N)
//Space Complexity: O(N)
//As declaring global variable method is not good, so we should do internally

//Array: {5, 4, 3, 2, 1}
// Inversions: (5,4), (5,3), (5,2), (5,1), (4,3), (4,2), (4,1), (3,2), (3,1), (2,1)
// Total count: 10

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left=low;
    int right= mid+1;
    int count=0;

    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else{
            temp.push_back(arr[right]);
            count+= (mid-left+1);
            right++;
        }
    }

    while(left<= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<= high; i++){
        arr[i]= temp[i-low];
    }
    
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int count=0;
    if(low>= high) return count;
    int mid= (low+high)/2;
    count+= mergeSort(arr, low,mid);
    count+= mergeSort(arr, mid+1, high);
    count+= merge(arr, low, mid, high);
    return count;
}

int numberOfInversions(vector<int>& a, int n) {
    return mergeSort(a, 0, n-1);
}

int main() {
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: " << cnt << endl;
    return 0;
}
