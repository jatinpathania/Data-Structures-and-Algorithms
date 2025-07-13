#include <iostream>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    queue<int> q;
    stack<int> s;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}