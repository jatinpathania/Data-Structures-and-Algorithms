#include<iostream>
using namespace std;
void generateParentheses(int open, int close, string output){
    if(open==0 && close==0){
        cout<<output<<" ";
        return;
    }
    if(open>0){
        generateParentheses(open-1,close,output+'(');
    }
    if(close>open){
        generateParentheses(open,close-1,output+')');
    }
}

int main(){
    int n;
    cout<<"Enter number of pairs of parentheses: ";
    cin>>n;
    cout << "All valid combinations of parentheses:\n";
    generateParentheses(n,n,"");
    return 0;
}
