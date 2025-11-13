#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n){
    unordered_map<int,int> mpp;
    int maxi=0;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+= A[i];
        if(sum==0){
            maxi= i+1;
        }
        else{
            if(mpp.find(sum)!=mpp.end()){
                maxi= max(maxi, i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
    }
    return maxi;
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int A[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "Length of longest subarray with sum 0: " << maxLen(A, n) << endl;
    return 0;
}
