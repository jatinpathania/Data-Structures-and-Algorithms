#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(int ind,string output,string mappings[],string digits,vector<string>&ans){
        if(ind>=digits.length()){
            ans.push_back(output);
            return;
        }
        int num= digits[ind]-'0';
        string val= mappings[num];
        for(int i=0 ;i<val.length();i++){
            output.push_back(val[i]);
            solve(ind+1,output,mappings,digits,ans);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits){
        vector<string>ans;
        string output="";
        if(digits.length()==0){
            return ans;
        }
        int ind=0;
        string mappings[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(ind,output,mappings,digits,ans);
        return ans;
    }
};

int main(){
    Solution sol;
    string digits;
    cout <<"Enter digits (2-9):";
    cin >>digits;
    vector<string> combinations = sol.letterCombinations(digits);
    cout<<"Letter Combinations:\n";
    for(const string &combo : combinations){
        cout<<combo<< " ";
    }
    cout<<endl;
    return 0;
}
