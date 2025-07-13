#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<char> uset;
    string str= "abcdefabcdef";
    for(int i=0;i<str.length();i++){
        uset.insert(str[i]);
    }
    if(uset.size()==str.length()){
        cout<<"There are no unique elements present in the unordered set"<<endl;
    }
    else{
        cout<<"Unique elements are present";
    }
return 0;
}