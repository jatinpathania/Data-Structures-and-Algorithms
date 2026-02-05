#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isPalindrome(string s, int start,int end){
        while(start<=end){
            if(s[start++]!= s[end--]) return false;
        }
        return true;
    }
    void solve(int ind,string s,vector<string>& path,vector<vector<string>>& res){
        if(ind==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=ind; i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind, i -ind +1));
                solve(i+1,s,path,res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s){
        vector<vector<string>> res;
        vector<string> path;
        solve(0,s,path,res);
        return res;
    }
};

int main(){
    Solution sol;
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    vector<vector<string>> partitions = sol.partition(s);
    cout<<"Palindrome partitions:\n";
    for(const auto &part : partitions){
        for(const string &word : part){
            cout<<word<< " ";
        }
        cout<<endl;
    }
    return 0;
}
