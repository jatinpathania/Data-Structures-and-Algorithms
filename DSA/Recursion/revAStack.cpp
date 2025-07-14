#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int temp= s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(temp);
}
void reverseStack(stack<int>&s){
    if(s.empty()) return;
    int x= s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,x);
}
int main(){
    stack<int> s;
    cout<<"Enter no of elements of stack:";
    int n;
    cin>>n;
    cout<<"Enter elements of stack:";
    int value;
    for(int i=0; i<n ;i++){
        cin>>value;
        s.push(value);
    }

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" "<<endl;
        s.pop();
    }
    return 0;
}