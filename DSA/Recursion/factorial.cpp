#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n== 0 || n== 1) return 1;
    return n* factorial(n- 1);
}

int main(){
    int n1= 5;
    int result1= factorial(n1);
    cout<< "Factorial of " << n1 << " = " << result1 << endl;

    int n2= 6;
    int result2= factorial(n2);
    cout<< "Factorial of " << n2 << " = " << result2 << endl;
    return 0;
}
