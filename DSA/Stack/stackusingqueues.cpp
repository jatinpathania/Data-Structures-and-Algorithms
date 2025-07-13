//if we have to perform a large no. of ops of push then we should use two queues but if more operations are of pop then we should use single queue
#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {}
    void push(int x) {
        q1.push(x);
    }
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        swap(q1, q2);
        return res;
    }
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1, q2);
        return res;
    }
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << "Top element: " << obj->top() << endl;
    cout << "Pop element: " << obj->pop() << endl;
    cout << "Pop element: " << obj->pop() << endl;
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl;
    cout << "Pop element: " << obj->pop() << endl;
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl;
    delete obj;
    return 0;
}



// Using single queue

// #include <iostream>
// #include <queue>
// using namespace std;

// class MyStack {
// public:
//     queue<int> q;

//     MyStack() {}

//     void push(int x) {
//         q.push(x);
//         int size = q.size();
//         for (int i = 1; i < size; ++i) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop() {
//         int res = q.front();
//         q.pop();
//         return res;
//     }

//     int top() {
//         return q.front();
//     }

//     bool empty() {
//         return q.empty();
//     }
// };

// int main() {
//     MyStack* obj = new MyStack();
//     obj->push(1);
//     obj->push(2);
//     obj->push(3);
//     cout << "Top element: " << obj->top() << endl;
//     cout << "Pop element: " << obj->pop() << endl;
//     cout << "Pop element: " << obj->pop() << endl;
//     cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl;
//     cout << "Pop element: " << obj->pop() << endl;
//     cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl;
//     delete obj;
//     return 0;
// }
