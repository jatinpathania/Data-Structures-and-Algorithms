#include <iostream>
#include <vector>
using namespace std;

int largestElement(vector<int>& arr, int n){
    int min= arr[0];
    for(int i=0 ; i<n ; i++){
        if(arr[i]> min){
            min= arr[i];
        }
    }
    return min;
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
    int result = largestElement(arr, n);
    cout << "Largest element in the array is: " << result << endl;
    return 0;
}
