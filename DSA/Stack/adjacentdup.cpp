#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack<char> s;
    string str="xyzppzymmsxpppp";
    string res;
    for(int i=0; i<str.length() ;i++){
        if(!s.empty() && s.top()==str[i]){
            s.pop();
        }
        else{
            s.push(str[i]);
        }
    }
    
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    cout<<res;
return 0;
}