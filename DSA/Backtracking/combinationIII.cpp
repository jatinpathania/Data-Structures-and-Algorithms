#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    void findCombinations(int ind,int k,int n,vector<int>& ds, vector<vector<int>>& ans){
        if (k==0 && n==0) {
            ans.push_back(ds);
            return;
        }
        for (int i =ind;i<= 9; i++) {
            if (i>n) break;
            ds.push_back(i);
            findCombinations(i+1, k-1, n-i,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k,int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(1,k,n,ds,ans);
        return ans;
    }
};

int main(){
    Solution sol;
    int k =3,n =7;
    vector<vector<int>> res = sol.combinationSum3(k,n);
    cout<<"Combinations are:\n";
    for(auto comb: res) {
        for(int num :comb)
            cout<<num<< " ";
        cout<<endl;
    }

    return 0;
}
