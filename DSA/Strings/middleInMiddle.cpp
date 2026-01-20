#include <iostream>
#include <vector>
using namespace std;

void printMiddleWord(string s) {
    vector<string> words;
    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' '){
            if (temp != "") {
                words.push_back(temp);
                temp = "";
            }
        } else {
            temp += s[i];
        }
    }

    if (temp != "")
        words.push_back(temp);

    int n = words.size();

    if (n % 2 == 1) {
        cout << words[n / 2];
    } else {
        cout << words[n / 2 - 1] << " " << words[n / 2];
    }
}

int main() {
    string s;
    getline(cin, s);

    printMiddleWord(s);

    return 0;
}
