#include<bits/stdc++.h>
using namespace std;
// void sortStack(stack<int>& s){
//     vector<int> arr;
//     while(!s.empty()){
//         arr.push_back(s.top());
//         s.pop();
//     }
//     sort(arr.begin(),arr.end());
//     for(int i=0;i<arr.size();i++){
//         s.push(arr[i]);
//     }
// }

// using recursion


void insertInStack(int x, stack<int>& s){
    if(s.size()==0 || s.top()<x){
        s.push(x);
    }
    else{
        int a= s.top();
        s.pop();
        insertInStack(x,s);
        s.push(a);
    }
}
void reverseStack(stack<int>& s){
    if(s.size()>0){
        int x= s.top();
        s.pop();
        reverseStack(s);
        insertInStack(x,s);
    }
}

void sortStack(stack<int>&s){
    reverseStack(s);
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

    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<" "<<endl;
        s.pop();
    }
    return 0;
}