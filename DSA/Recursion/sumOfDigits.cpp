#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int n){
    if(n== 0) return 0;
    return (n% 10)+ sumOfDigits(n/ 10);
}

int main(){
    int n1= 12345;
    int result1= sumOfDigits(n1);
    cout<< "Sum of digits of " << n1 << " = " << result1 << endl;

    int n2= 987;
    int result2= sumOfDigits(n2);
    cout<< "Sum of digits of " << n2 << " = " << result2 << endl;
    return 0;
}
