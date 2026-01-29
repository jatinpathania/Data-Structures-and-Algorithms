// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {1,3,5,2,2};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     for (int i = 0; i < n; i++) {
//         int leftSum = 0,rightSum = 0;
//         for(int j = 0; j<i; j++) {
//             leftSum += arr[j];
//         }
//         for(int j = i+1; j<n; j++) {
//             rightSum += arr[j];
//         }
//         if(leftSum==rightSum) {
//             cout << "Equilibrium index found at: " << i << endl;
//         }
//     }
//     return 0;
// }



// Optimal code 

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int totalSum = 0, leftSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    for (int i = 0; i < n; i++) {
        totalSum -= arr[i];
        if (leftSum == totalSum) {
            cout << "Equilibrium index found at: " << i << endl;
        }
        leftSum += arr[i];
    }

    return 0;
}
