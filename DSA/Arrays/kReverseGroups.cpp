#include <bits/stdc++.h>
using namespace std;

void reverseInGroups(int arr[], int n, int k) {
    for(int i=0; i<n ; i+=k){
        int left=i;
        int right= min(i+k-1, n-1);
        while(left <right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    reverseInGroups(arr, n, k);
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    return 0;
}
