#include <bits/stdc++.h>
using namespace std;
        
//Time complexity- O(logM)
class Solution {
public:
    // return 1 if == m
    // return 0 if < m
    // return 2 if > m
    int func(int mid, int n, int m){
        long long ans=1;
        for(int i=1 ; i<=n ;i++){
            ans= ans*mid;
            if(ans >m) return 2;
        }
        if(ans== m) return 1;
        return 0;
    }
    int nthRoot(int n, int m){
        int low=1, high= m;
        while(low<= high){
            int mid= low+(high-low)/2;
            int midN= func(mid, n, m);
            if(midN == 1) return mid;
            else if(midN == 0){
                low= mid+1;
            }
            else{
                high= mid-1; 
            }
        }
        return -1;
    }
};

int main(){
    Solution obj;
    int result = obj.nthRoot(3, 27);
    cout<<result;
    return 0;
}