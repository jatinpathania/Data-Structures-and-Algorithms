#include<bits/stdc++.h>
using namespace std;

//optimal
void rotate(vector < vector < int >> & matrix) {
    //transpose
    int n= matrix.size();
    for(int i=0; i<n-1 ;i++){
        for(int j= i+1; j< n ;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        //reverse
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "\n";
    }
}

//brute force - O(n)
// vector<vector<int>> rotate(vector < vector < int >> & matrix) {
//     int n= matrix.size();
//     vector<vector<int>> rotated(n, vector<int>(n,0));
//     int arr[n][n];
//     for(int i=0; i<n ;i++){
//         for(int j=0; j<n ;j++){
//             rotated[j][n-i-1]= matrix[i][j];
//         }
//     }
//     return rotated;
// }

// int main() {
//     vector < vector < int >> arr;
//     arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     vector<vector<int>>rotated= rotate(arr);
//     cout << "Rotated Image" << endl;
//     for (int i = 0; i < rotated.size(); i++) {
//     for (int j = 0; j < rotated[0].size(); j++) {
//         cout << rotated[i][j] << " ";
//     }
//     cout << "\n";
//     }
// }
