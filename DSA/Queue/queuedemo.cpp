#include <iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    // cout<<"Is empty: "<<q.empty()<<" Size: "<<q.size()<<endl;
    // q.push(10);
    // q.push(11);
    // cout<<"Is empty: "<<q.empty()<<" Size: "<<q.size()<<endl;
    // q.pop();
    // q.pop();
    // cout<<"Is empty: "<<q.empty()<<" Size: "<<q.size()<<endl;
    // cout<<"Front: "<<q.front()<<" Back: "<<q.back()<<endl;

    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    //printing a queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
return 0;
}