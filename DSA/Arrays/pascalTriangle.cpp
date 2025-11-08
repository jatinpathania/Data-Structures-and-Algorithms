// Find Pascal Element

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     long long findPascalElement(int r, int c){
//         int n= r-1;
//         int k= c-1;
//         long long res=1;
//         for(int i=0; i<k ; i++){
//             res*= (n-1);
//             res/= (i+1);
//         }
//         return res;
//     }
// };

// int main() {
//     Solution sol;
//     int r = 5, c = 3;
//     cout << sol.findPascalElement(r, c);
//     return 0;
// }




//Generate nth row
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<long long> getNthRow(int N){
//         vector<long long> res;
//         long long ans=1;
//         res.push_back(ans);
//         for(int i=1; i<N; i++){
//             ans*= (N-i);
//             ans/= i;
//             res.push_back(ans);
//         }
//         return res;
//     }
// };

// int main() {
//     int N = 5; 
//     Solution sol;
//     vector<long long> result = sol.getNthRow(N);

//     for (auto num : result) {
//         cout << num << " ";
//     }
//     return 0;
// }


// Print pascal triangle  - O(N²)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> generate(int row){
        vector<int> res;
        long long ans=1;
        res.push_back(ans);
        for(int col=1 ; col< row; col++){
            ans*= (row-col);
            ans/= col;
            res.push_back(ans);
        }
        return res;
    }
    vector<vector<int>> pascalTriangle(int numRows){
        vector<vector<int>> res;
        for(int i=1; i<= numRows; i++){
            vector<int> ans= generate(i);
            res.push_back(ans);
        }
        return res;
    }
};

int main() {
    Solution obj;
    int n = 5;
    vector<vector<int>> result = obj.pascalTriangle(n);
    for (auto &row : result) {
        for (auto &val : row) cout << val << " ";
        cout << endl;
    }
}