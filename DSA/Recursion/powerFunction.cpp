#include<bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp){
    if(exp== 0) return 1;
    if(exp== 1) return base;
    long long half= power(base, exp/ 2);

    if(exp% 2== 0){
        return half* half;
    }
    else{
        return base* half* half;
    }
}

int main(){
    long long base1= 2;
    long long exp1= 10;
    long long result1= power(base1, exp1);
    cout<< base1 << "^" << exp1 << " = " << result1 << endl;

    long long base2= 3;
    long long exp2= 8;
    long long result2= power(base2, exp2);
    cout<< base2 << "^" << exp2 << " = " << result2 << endl;
    return 0;
}
