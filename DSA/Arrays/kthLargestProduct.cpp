#include<bits/stdc++.h>
using namespace std;

long long kthLargestProduct(int arr[], int product[], int n, int m) {
    sort(arr, arr+n , greater<int>());
    long long ans=1;
    for(int i=0; i<m ;i++){
        int k= product[i];
        if(k<=0 || k>n) continue;
        ans*= arr[k-1];
    }
    return ans;
;}

int main() {
    int arr[] = {25, 30, 10, 1, 5, 20, 40};
    int product[] = {2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(product) / sizeof(product[0]);
    long long res = kthLargestProduct(arr, product, n, m);
    cout<<"The kth Largest Product is "<< res << endl;
    return 0;
}
