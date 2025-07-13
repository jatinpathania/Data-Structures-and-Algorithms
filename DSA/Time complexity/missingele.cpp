// #include <iostream>
// using namespace std;
// int main()
// {
//     int n=10;
//     int arr[n-1]={5,7,10,1,3,2,8,4,9};
//     bool arr1[n];
//     for(int i=0 ; i<n-1 ;i++){
//         arr1[arr[i]]=true;
//     }
//     for(int i=1 ; i<=n ;i++){
//         if(!arr1[i]){
//             cout<<i<<endl;
//             break;
//         }
//     }
    
// return 0;
// }
//O(n)



// Optimal code with time complexity O(n)
#include <iostream>
using namespace std;
int main()
{
    int n=10;
    int arr[n-1]={5,7,10,1,3,2,8,4,9};
    int consecutiveSum= (n*(n+1))/2;
    int sum= 0;
    for(int i=0 ; i<n-1 ;i++){
        sum+=arr[i];
    }
    int missingNumber = consecutiveSum - sum;
    cout<<missingNumber<<endl;
    
return 0;
}



// #include <iostream>
// using namespace std;

// int findMissingElement(int arr[], int n) {
//     // Iterate through all numbers from 1 to n
//     for (int i = 1; i <= n; i++) {
//         bool found = false;

//         // Check if `i` exists in the array
//         for (int j = 0; j < n - 1; j++) {
//             if (arr[j] == i) {
//                 found = true;
//                 break;
//             }
//         }

//         // If `i` is not found, it is the missing number
//         if (!found) {
//             return i;
//         }
//     }

//     return -1; // This should never happen for valid input
// }

// int main() {
//     int arr[] = {1, 2, 4, 5, 6}; // Example array (missing 3)
//     int n = 6; // Total number of elements including the missing one

//     cout << "Missing element: " << findMissingElement(arr, n) << endl;

//     return 0;
// }
// O(n^2)


