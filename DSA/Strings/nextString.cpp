#include <bits/stdc++.h>
using namespace std;

string nextGreaterNumber(string s) {
    int n = s.size();
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) i--;

    if (i < 0) return "-1";

    int j = n - 1;
    while (s[j] <= s[i]) j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    return s;
}

int main() {
    string num = "1234";
    cout << nextGreaterNumber(num) << endl;
    return 0;
}
