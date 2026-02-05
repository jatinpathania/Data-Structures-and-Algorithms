#include<bits/stdc++.h>
using namespace std;

void primeFactor(int n, int divisor= 2){
    if(n< 2) return;

    if(n% divisor== 0){
        cout<< divisor<< " ";
        primeFactor(n/ divisor, divisor);
    }
    else{
        primeFactor(n, divisor+ 1);
    }
}

int main(){
    int n1= 60;
    cout<< "Prime factors of " << n1 << " = ";
    primeFactor(n1);
    cout<< endl;

    int n2= 100;
    cout<< "Prime factors of " << n2 << " = ";
    primeFactor(n2);
    cout<< endl;
    return 0;
}
