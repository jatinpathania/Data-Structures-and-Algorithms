#include <iostream>
#include <vector>
using namespace std;

int countChunks(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    int i = 0;
    while(i < n) {
        int minVal = arr[i];
        int maxVal = arr[i];
        int j = i;

        while(j + 1 < n) {
            int newMin = min(minVal, arr[j+1]);
            int newMax = max(maxVal, arr[j+1]);
            if(newMax - newMin == (j + 1 - i)) {
                j++;
                minVal = newMin;
                maxVal = newMax;
            } else {
                break;
            }
        }
        count++;
        i = j + 1;
    }
    return count;
}

int main() {
    vector<int> arr = {4, 3, 2, 1, 6, 8, 9, 15, 12, 13, 14};

    cout << countChunks(arr);

    return 0;
}