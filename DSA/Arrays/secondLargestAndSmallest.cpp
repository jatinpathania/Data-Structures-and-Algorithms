#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargestElement(vector<int>& arr, int n){
    int largest= arr[0];
    int sLargest= -1;
    for(int i=1 ; i<n ; i++){
        if(arr[i]> largest){
            sLargest= largest;
            largest= arr[i];
        }
        else if(arr[i]< largest && arr[i]> sLargest){
            sLargest= arr[i];
        }
    }
    return sLargest;
}

int secondSmallestElement(vector<int>& arr, int n){
    int smallest= arr[0];
    int sSmallest= INT_MAX;
    for(int i=1 ; i<n ; i++){
        if(arr[i] < smallest){
            sSmallest= smallest;
            smallest= arr[i];
        }
        else if(arr[i] != smallest && arr[i] < sSmallest){
            sSmallest= arr[i];
        }
    }
    return sSmallest;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = secondLargestElement(arr, n);
    cout << "Second Largest element in the array is: " << result << endl;
    int result1 = secondSmallestElement(arr, n);
    cout << "Second Smallest element in the array is: " << result1 << endl;
    return 0;
}
