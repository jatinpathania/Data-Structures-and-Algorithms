#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue(){}

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()){
            int res=s2.top();
            s2.pop();
            return res;
        }
        return -1;
    }

    int front() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()){
            return s2.top();
        }
        return -1;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->enqueue(1);
    obj->enqueue(2);
    obj->enqueue(3);
    cout << "Front element: " << obj->front() << endl;
    cout << "Dequeue element: " << obj->dequeue() << endl;
    cout << "Dequeue element: " << obj->dequeue() << endl;
    cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << endl;
    cout << "Dequeue element: " << obj->dequeue() << endl;
    cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << endl;
    delete obj;
    return 0;
}
