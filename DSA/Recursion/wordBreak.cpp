#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<string> st;
    int t[301];
    bool solve(int idx,string& s){
        if(idx>= s.length()) return true;
        if(t[idx]!=-1) return t[idx];
        if(st.find(s)!=st.end()) return true;
        
        for(int l=1;l+idx<=s.length() ;l++){
            string temp= s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(idx+l,s)){
                return t[idx]=true;
            }
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict){
        int n= s.length();
        memset(t,-1,sizeof(t));
        for(string &word: wordDict){
            st.insert(word);
        }
        return solve(0,s);
    }
};

int main(){
    string s ="leetcode";
    vector<string> wordDict ={"leet", "code"};
    Solution solution;
    bool result = solution.wordBreak(s,wordDict);
    if(result)
        cout<<"The string can be segmented into dictionary words."<<endl;
    else
        cout<<"The string cannot be segmented."<< endl;
    return 0;
}
