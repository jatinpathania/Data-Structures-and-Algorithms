#include <bits/stdc++.h>
using namespace std;

//Optimal 1
int missingNumber(vector<int>&a, int N) {
    int xor1= 0, xor2=0 ;
    int n= N-1;
    for(int i=0 ;i<n ;i++){
        xor2^= a[i];
        xor1^= i+1;
    }
    xor1^= N;
    return xor1^xor2;
}

//Optimal 2
// int missingNumber(vector<int>&a, int N) {
//     int internalSum=0;
//     for(int num: a){
//         internalSum+= num;
//     }
//     int total= N*(N+1)/2;
//     return total-internalSum;
// }

int main(){
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
