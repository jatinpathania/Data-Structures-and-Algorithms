#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructer
    Node(int value){
        data = value;
        next= NULL;
    }
};
class myQueue{
    public:
    Node* front=NULL;
    Node* rear=NULL;

    //isEmpty
    bool isEmpty(){
        return front==NULL;
    }

    //push
    void push(int data){
        Node* newNode= new Node(data);
        if (isEmpty()){
            rear= front=newNode;
        }
        rear->next= newNode;
        rear= newNode;
    }

    //pop
    void pop(){
        Node* temp= front;
        front= front->next;
        temp->next = NULL;
        delete temp;
    }

    int rearVal(){
        return rear->data;
    }

    void display(){
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main()
{
    myQueue q;
    q.push(1);
    q.push(2);
    q.push(9);
    q.display();
return 0;
}