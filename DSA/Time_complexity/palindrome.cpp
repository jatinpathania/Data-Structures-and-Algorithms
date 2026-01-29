#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    int arr[n] = {1, 2, 4, 9, 4, 2, 1};
    bool flag = true;

    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}

//O(n)
