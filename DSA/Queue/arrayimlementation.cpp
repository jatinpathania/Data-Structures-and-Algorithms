#include <iostream>
using namespace std;
class myQueue{
    private:
    int *queue;;
    int capacity;
    int size;
    int front;
    int rear;
    public:
    myQueue(int capacity){
        this->capacity = capacity;
        queue= new int[capacity];
        size=0;
        front=0;
        rear=-1;
    }

    bool isFull(){
        if(size==capacity){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(size==0){
            return true;
        }
        return false;
    }

    void enqueue(int ele){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        rear+=1;
        queue[rear]=ele;
        size++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front+=1;
        size--;
    }

    int Front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return queue[front];
    }

    int Rear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return queue[rear];
    }
    
    int Size(){
        return size;
    }
};
int main()
{
    myQueue o1(7);
    o1.enqueue(1);
    o1.enqueue(2);
    o1.enqueue(3);
    o1.enqueue(4);
    o1.dequeue();
    cout<<o1.Front()<<endl;
return 0;
}