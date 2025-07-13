#include <iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack<int> st;
    // cout<<st.empty()<<" "<<st.size()<<endl;
    // st.push(10);
    // cout<<st.empty()<<" "<<st.size()<<endl;
    // st.push(11);
    // st.pop();
    // st.pop();
    // cout<<st.empty()<<" "<<st.size()<<endl;

    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);

    //for loop cannot be used to print stack as size is dynamically changing
    //traversing a stack
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
return 0;
}