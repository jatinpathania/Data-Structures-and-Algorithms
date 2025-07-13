#include <iostream>
using namespace std;

int main() {
    string str = "Code Quotient Loves Code";
    int i = 0, j = str.length() - 1;

    while (i < str.length() && str[i] == ' ') i++;
    int firstEnd = i;

    while (firstEnd < str.length() && str[firstEnd] != ' ') firstEnd++;

    int lastStart = j;
    while (lastStart >= 0 && str[lastStart] == ' ') lastStart--;
    int lastEnd = lastStart;
    while (lastStart >= 0 && str[lastStart] != ' ') lastStart--;

    cout << str.substr(i, firstEnd - i);

    for (int k = firstEnd; k <= lastStart; k++) {
        int wordStart = k;
        while (k < str.length() && str[k] != ' ') k++;
        if (k > wordStart) {
            cout << " " << str.substr(wordStart, k - wordStart);
        }
    }

    cout << " " << str.substr(lastStart + 1, lastEnd - lastStart) << endl;
    return 0;
}
