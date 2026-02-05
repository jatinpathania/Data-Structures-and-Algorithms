#include<bits/stdc++.h>
using namespace std;

void binaryEquivalent(int n){
    if(n== 0) return;
    binaryEquivalent(n/ 2);
    cout<< (n% 2);
}

int main(){
    int n1= 5;
    cout<< "Binary equivalent of " << n1 << " = ";
    binaryEquivalent(n1);
    cout<< endl;

    int n2= 25;
    cout<< "Binary equivalent of " << n2 << " = ";
    binaryEquivalent(n2);
    cout<< endl;

    int n3= 100;
    cout<< "Binary equivalent of " << n3 << " = ";
    binaryEquivalent(n3);
    cout<< endl;

    return 0;
}
