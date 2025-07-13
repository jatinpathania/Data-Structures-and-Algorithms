#include <iostream>
using namespace std;

int main() {
    string str= "Code Quotient Loves Code";
    int start= 0;
    for (int i= 0; i<= str.length(); i++) {
        if (i== str.length() || str[i]== ' ') {
            int end= i-1;
            while (start<end) {
                char temp= str[start];
                str[start]= str[end];
                str[end]= temp;
                start++;
                end--;
            }
            start = i+1;
        }
    }
    cout<<str<<endl;
    return 0;
}
