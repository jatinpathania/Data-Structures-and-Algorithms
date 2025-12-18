#include <bits/stdc++.h>
using namespace std;

//optimal
class Solution {
public:
    bool isValid(string s){
        int minOpen=0;
        int maxOpen=0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                minOpen++;
                maxOpen++;
            }
            else if(s[i]== ')'){
                minOpen--;
                maxOpen--;
            }
            else{
                minOpen--;
                maxOpen++;
            }
            if(minOpen<0) minOpen=0;
            if(maxOpen<0) return false;
        }
        return minOpen==0;
    }
};

// brute force - O(3^n)
// class Solution {
// public:
//     bool checkingValidness(string& s, int i, int count){
//         if(count <0) return false;
//         if(i == s.length()) return count ==0;
//         if(s[i] == '('){
//             return checkingValidness(s,i+1, count+1);
//         }
//         else if(s[i]== ')'){
//             return checkingValidness(s,i+1, count-1);
//         }
//         else{
//             return checkingValidness(s,i+1, count) || checkingValidness(s,i+1, count+1) || checkingValidness(s,i+1, count-1);
//         }
//     }
//     bool isValid(string s){
//         if(checkingValidness(s,0,0)) return true;
//         else return false;
//     }
// };


int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    Solution sol;
    if (sol.isValid(s)) {
        cout << "Valid parenthesis string" << endl;
    } else {
        cout << "Invalid parenthesis string" << endl;
    }
    return 0;
}