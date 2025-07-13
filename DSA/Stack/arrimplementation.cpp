#include <iostream>
using namespace std;
class myStack{
    private:
    int *stack;    //array bnare hm
    int capacity;
    int size;
    int top;
    public:
    myStack(int capacity){
        this->capacity= capacity;
        stack = new int[capacity];
        size = 0;
        top = -1;
    }

    bool isFull(){
        if(top==capacity){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    int Top(){
        if(isEmpty()){
            cout<<"Stack is Empty";
            return -1;
        }
        return stack[top];
    }
    void push(int ele){
        if(isFull()){
            cout<<"Stack is full";
            return;
        }
        top+=1;
        stack[top]=ele;
        size++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty";
            return -1;
        }
        int ele=stack[top];
        top-=1;
        return ele;
    }
};
int main()
{
    myStack stack1(10);
    stack1.push(5);
    stack1.push(10);
    stack1.pop();
    cout<<stack1.Top();
return 0;
}