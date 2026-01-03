#include<bits/stdc++.h>
using namespace std;

long long kthSmallestProduct(vector<int> arr, vector<int> product) {
    sort(arr.begin(), arr.end());
    long long ans=1;
    int n= arr.size();
    for(int k: product){
        if(k<=0 || k>n) continue;
        ans*= arr[k-1];
    }
    return ans;
;}

int main() {
    vector<int> arr = {25, 30, 10, 1, 5, 20, 40};
    vector<int> product = {2, 4, 1};
    long long res = kthSmallestProduct(arr, product);
    cout<<"The kth Smallest Product is "<< res << endl;
    return 0;
}
