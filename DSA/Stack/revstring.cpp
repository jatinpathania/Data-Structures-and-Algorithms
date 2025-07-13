#include <iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack <char> s;
    string str="xyzabc";
    for(int i=0 ; i<str.length();i++){
        s.push(str[i]);
    }

    string res="";
    while(!s.empty()){
        res= res+s.top();
        s.pop();
    }
    cout<<res;
return 0;
}