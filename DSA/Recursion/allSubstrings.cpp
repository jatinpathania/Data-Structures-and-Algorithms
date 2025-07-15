#include<iostream>
#include<vector>
using namespace std;
void generateSubsequences(string input,string output,vector<string>& result){
    if(input.empty()){
        result.push_back(output);
        return;
    }
    generateSubsequences(input.substr(1),output+input[0],result);
    generateSubsequences(input.substr(1),output,result);
}
int main(){
    string str ="abc";
    vector<string>powerSet;
    generateSubsequences(str,"",powerSet);
    cout<<"Power Set (Subsequences):\n";
    for(const string& subseq:powerSet){
        cout<<"\""<<subseq<<"\"\n";
    }
    return 0;
}
