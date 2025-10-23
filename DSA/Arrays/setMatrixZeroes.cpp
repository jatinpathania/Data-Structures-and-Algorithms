#include <bits/stdc++.h>
using namespace std;

// optimal approach
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    // int col[m]= {0} ->> matrix[0][..]
    // int row[n]= {0} ->> matrix[..][0]
    int col0= 1;
    for(int i=0;i< n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                //mark the ith row
                matrix[i][0]= 0;
                //mark the jth col
                if(j!=0){
                    matrix[0][j] =0;
                }
                else{
                    col0= 0;
                }
            }
        }
    }

    for(int i=1; i<n ;i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j] !=0){
                //check for col & row
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]= 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0) for(int j=0; j<m ;j++) matrix[0][j] = 0;

    if(col0 == 0) for(int i=0; i<n ;i++) matrix[i][0] =0;
    return matrix;
}

//better sol
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
//     int row[n]= {0};
//     int col[m] ={0};
//     for(int i=0; i<n ;i++){
//         for(int j=0; j<m ;j++){
//             if(matrix[i][j] == 0){
//                 row[i]= 1;
//                 col[j]= 1;
//             }
//         }
//     }

//     for(int i=0; i<n ;i++){
//         for(int j=0; j<m ;j++){
//             if( row[i] || col[j] ){
//                 matrix[i][j]= 0;
//             }
//         }
//     }
//     return matrix;
// }

//brute force
    // void markRow(vector<vector<int>> &matrix, int i, int m){
    //     for(int j=0; j<m ;j++){
    //         if(matrix[i][j]!=0){
    //             matrix[i][j]= -1;
    //         }
    //     }
    // }

    // void markCol(vector<vector<int>> &matrix, int j, int n){
    //     for(int i=0; i<n ;i++){
    //         if(matrix[i][j]!=0){
    //             matrix[i][j]= -1;
    //         }
    //     }
    // }

    // vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    //     for(int i=0; i<n ;i++){
    //         for(int j=0; j<m ;j++){
    //             if(matrix[i][j] == 0){
    //                 markRow(matrix, i, m); // send cols length
    //                 markCol(matrix, j, n);  // send rows length
    //             }
    //         }
    //     }

    //     for(int i=0; i<n ;i++){
    //         for(int j=0; j<m ;j++){
    //             if(matrix[i][j] == -1){
    //                 matrix[i][j]= 0;
    //             }
    //         }
    //     }
    //     return matrix;
    // }

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
