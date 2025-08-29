#include <bits/stdc++.h>
using namespace std;

void bubbleSortRecursive(int arr[], int n) {
    if (n == 1) return;
    // Do one pass of Bubble Sort
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    bubbleSortRecursive(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i]<<" ";
    return 0;
}
 