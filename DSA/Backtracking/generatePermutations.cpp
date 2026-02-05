#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& arr, int idx, vector<vector<int>>& res){
    if(idx== arr.size()){
        res.push_back(arr);
        return;
    }

    for(int i= idx; i< arr.size(); i++){
        swap(arr[i], arr[idx]);
        helper(arr, idx+ 1, res);
        swap(arr[i], arr[idx]);
    }
}

vector<vector<int>> permute(vector<int> arr){
    vector<vector<int>> res;
    helper(arr, 0, res);
    return res;
}

int main(){
    vector<int> arr1= {1, 2, 3};
    vector<vector<int>> result1= permute(arr1);
    cout<< "Permutations of { ";
    for(int i= 0; i< arr1.size(); i++){
        cout<< arr1[i];
        if(i< arr1.size()- 1) cout<< ", ";
    }
    cout<< " }:" << endl;
    for(const vector<int>& perm : result1){
        cout<< "{ ";
        for(int i= 0; i< perm.size(); i++){
            cout<< perm[i];
            if(i< perm.size()- 1) cout<< ", ";
        }
        cout<< " }" << endl;
    }
    cout<< endl;
    return 0;
}
