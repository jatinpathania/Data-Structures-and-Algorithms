#include<bits/stdc++.h>
using namespace std;

void solver(vector<int>& arr, int i, vector<int>& ans, vector<vector<int>>& res){
    if(i == arr.size()){
        res.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    solver(arr, i+1, ans, res);
    ans.pop_back();
    solver(arr, i+1, ans, res);
}

vector<vector<int>> generateAllSubsets(vector<int>& arr){
    vector<vector<int>> res;
    vector<int> ans;
    solver(arr, 0, ans, res);
    return res;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> subsets = generateAllSubsets(arr);
    cout << "All Subsets:" << endl;
    for(int i = 0; i < subsets.size(); i++){
        cout << "{ ";
        for(int j= 0; j< subsets[i].size(); j++){
            cout<< subsets[i][j];
            if(j< subsets[i].size()- 1) cout << ", ";
        }
        cout<<" }" << endl;
    }
    return 0;
}