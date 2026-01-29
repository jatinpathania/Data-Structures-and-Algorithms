#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node (int val){
        data= val;
        next= NULL;
    }
};

class circularList{
    Node* head;
    Node* tail;
    public:
    circularList(){
        head= NULL;
        tail= NULL;
    }
    
    void insertAtHead(int val){
        Node* newNode= new Node(val);
        if(tail==NULL){
            head=tail= newNode;
            tail->next= head;
        }
        else{
            newNode->next= head;
            head= newNode;
            tail->next= head;
        }
    }
    void insertAtTail(int val){
        Node* newNode= new Node(val);
        if(tail==NULL){
            head=tail= newNode;
            tail->next= head;
        }
        else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
    }

    void deleteAtHead(){
        if(head==NULL) return;
        else if(head==tail){ // single node
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp=head;
            head=head->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }

    void deleteAtTail(){
        if(head==NULL) return;
        else if(head==tail){ // single node
            delete head;
            head=tail=NULL;
        }
        else{
            Node* prev=head;
            while(prev->next!=tail){ 
                prev= prev->next;
            }
            Node* temp=tail;
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }

    void print(){
        if(head==NULL) return;
        cout<<head->data<<"->";
        Node* temp=head->next;
        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};
int main(){
    circularList cll;
    cll.insertAtHead(3);
    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.print();
    cll.insertAtTail(4);
    cll.print();
    cll.deleteAtHead();
    cll.print();
    cll.deleteAtTail();
    cll.print();
return 0;
}