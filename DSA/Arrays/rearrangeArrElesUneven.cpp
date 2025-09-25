#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int>A){
    vector<int> pos, neg;
    int n= A.size();
    for(int i=0; i<n ; i++){
        if(A[i]> 0){
            pos.push_back(A[i]);
        }
        else{
            neg.push_back(A[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i=0; i< neg.size(); i++){
            A[i*2]= pos[i];
            A[i*2+1]= neg[i]; 
        }
        int index= neg.size()*2;
        for(int i= neg.size() ;i< pos.size() ;i++){
            A[index++]= pos[i];
        }
    }
    else{
        for(int i=0; i< pos.size(); i++){
            A[i*2]= pos[i];
            A[i*2+1]= neg[i]; 
        }
        int index= pos.size()*2;
        for(int i= pos.size() ;i< neg.size() ;i++){
            A[index++]= neg[i];
        }
    }
    return A;
}

int main(){
    vector<int> A = {1,2,-4,-5, -8, 10 ,15 ,16 ,17};
    vector<int> ans = RearrangebySign(A);
    for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
    }
    return 0;
}