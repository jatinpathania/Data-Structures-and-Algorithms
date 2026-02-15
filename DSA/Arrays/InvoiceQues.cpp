#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countPairsInRange(vector<int> arr, int c, int d){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    long long count = 0;

    int left= 0, right = n-1;
    while(left < right) {
        long long sum = (long long)arr[left] + arr[right];
        if(sum<c){
            left++;
        }
        else if(sum > d) {
            right--;
        }
        else{
            count += (right-left);
            left++;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int c = 5, d = 7;
    long long result = countPairsInRange(arr, c, d);
    cout << "Pairs with sum in [" << c << ", " << d << "]: " << result << endl;
    return 0;
}