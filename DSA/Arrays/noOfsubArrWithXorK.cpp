#include <bits/stdc++.h>
using namespace std;

//optimal approach- O(N) and O(n log n ) space
int subarraysWithXorK(vector<int> a, int k){
    map<int,int> mpp;
    int Xor=0;
    int count=0;
    mpp[0]= 1;            // or simply write mpp[Xor]++ to store {0,1} in map
    for(int i=0; i<a.size(); i++){
        Xor^= a[i];
        int ele= Xor^k;
        count+= mpp[ele];         // stores 0 if not found.. we didn't use find here because storing 0 in mpp is harmless in this case
        mpp[Xor]++; 
    }
    return count;
}

int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: " << ans << "\n";
    return 0;
}
