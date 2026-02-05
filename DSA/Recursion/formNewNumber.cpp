#include<bits/stdc++.h>
using namespace std;

int evenDigits(int n){
    if(n== 0) return 0;

    int lD= n% 10;
    if(lD% 2== 0){
        return evenDigits(n/ 10)* 10+ lD;
    }
    return evenDigits(n/ 10);
}

int main(){
    int num= 8342116;
    int res= evenDigits(num);
    cout<< res<< endl;
    return 0;
}
