#include<bits/stdc++.h>
using namespace std;

//4 ques
//kth largest , kth smallest product, all k smaller or larger product
// for ex.. if product arr says 2 .. then ,, we find 2 largeest eles from arr and then find product of them

int kthLargestProduct(int arr[], int product[], int n, int m) {
    // Sort arr in descending order
    sort(arr, arr + n, greater<int>());

    long long prod = 1;

    for (int i = 0; i < m; i++) {
        int k = product[i];
        if (k <= 0 || k > n) continue; // invalid k, skip
        prod *= arr[k - 1]; // k-th largest element (1-based)
    }

    return prod;
}

int main() {
    int arr[] = {25, 30, 10, 1, 5, 20, 40};
    int product[] = {2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(product) / sizeof(product[0]);

    long long res = kthLargestProduct(arr, product, n, m);
    cout << res << endl;

    return 0;
}
