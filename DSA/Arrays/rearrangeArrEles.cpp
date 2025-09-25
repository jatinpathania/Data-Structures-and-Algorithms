#include<bits/stdc++.h>
using namespace std;

    //optimal
    vector<int> RearrangebySign(vector<int>A){
        int n= A.size();
        vector<int> res(n,0);
        int posIdx=0, negIdx=1;
        for(int i=0; i<n ;i++){
            if(A[i] <0){
                res[negIdx]= A[i];
                negIdx+=2;
            }
            else{
                res[posIdx]= A[i];
                posIdx+=2;
            }
        }
        return res;
    }
       


    // Brute force  -O(N) and O(N) space
    // vector<int> RearrangebySign(vector<int>A){
    //     int n = A.size();
    //     vector<int> pos;
    //     vector<int> neg;
    //     for(int num: A){
    //         if(num >=0) pos.push_back(num);
    //         if(num < 0) neg.push_back(num);
    //     }

    //     for(int i=0; i<n ;i++){
    //         A[i*2]= pos[i];
    //         A[i*2 +1]= neg[i];
    //     }
    //     return A;
    //}

int main(){
    vector<int> A = {1,2,-4,-5};
    vector<int> ans = RearrangebySign(A);
    for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
    }
    return 0;
}