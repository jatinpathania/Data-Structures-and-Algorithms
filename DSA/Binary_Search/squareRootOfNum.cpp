#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x){
        int low=1, high= x;
        while(low<= high){
            long long mid= low+(high-low)/2;
            long long val= (mid*mid);
            if(val <= x){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return high;
    }
};
    
int main() {
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;
}
