#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& student, vector<int>& cookie){
        int n= student.size();
        int m= cookie.size();
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());
        int i=0, j=0;
        while(i<n && j<m){
            if(student[i] <= cookie[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};

int main() {
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};

    Solution solver;

    int result = solver.findContentChildren(student, cookie);
    cout << "Maximum number of content students: " << result << endl;
    return 0;
}
