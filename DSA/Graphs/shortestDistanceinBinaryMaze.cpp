#include <bits/stdc++.h>
using namespace std;

//Time complexity-  O(4*N*M)
//Space complexity- O(N*M)

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    }
};

int main() {
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};
    vector<vector<int>> grid = {{1, 1, 1, 1},{1, 1, 0, 1},{1, 1, 1, 1},{1, 1, 0, 0},{1, 0, 0, 1}};

    Solution obj;
    int res = obj.shortestPath(grid, source, destination);
    cout << res << endl;
    return 0;
}