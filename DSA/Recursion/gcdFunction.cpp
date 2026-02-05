#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b== 0) return a;
    return gcd(b, a% b);
}

int main(){
    int a1= 48;
    int b1= 18;
    int result1= gcd(a1, b1);
    cout<< "GCD of " << a1 << " and " << b1 << " = " << result1 << endl;

    int a2= 100;
    int b2= 75;
    int result2= gcd(a2, b2);
    cout<< "GCD of " << a2 << " and " << b2 << " = " << result2 << endl;
    return 0;
}
