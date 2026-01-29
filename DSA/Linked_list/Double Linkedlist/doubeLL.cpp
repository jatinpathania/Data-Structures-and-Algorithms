#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node (int data){
        this-> data= data;
        next= prev = NULL;
    }
};

class DoubleyLI{
    public:
    Node* head;
    Node* tail;
    DoubleyLI(){
        head = tail = NULL;
    }

    //insertion
    void insertAtHead(int data){
        Node *newNode= new Node(data);
        if(head==NULL){
            head=newNode;
            tail= newNode;
            return;
        }
        newNode->next= head;
        head->prev= newNode;
        head= newNode;
    }

    void insertAtTail(int data){
        Node *newNode= new Node(data);
        if(head==NULL){
            head= newNode;
            tail= newNode;
            return;
        }
        tail->next= newNode;
        newNode->prev= tail;
        tail= newNode;
    }

    void insertAt(int data,int pos){
        if(pos<1){
            cout<<"Invalid Position!"<<endl;
            return;
        }
        if(pos==1){
            return insertAtHead(data);
        }
        int count= 1;
        Node *curr= head;
        while(curr!=NULL && count<pos){
            curr= curr->next;
            count++;
        }
        if(curr==NULL){
            cout<<"Invalid Position!"<<endl;
            return;
        }
        Node *newNode= new Node(data);
        newNode->next =curr->next;
        newNode->prev= curr;
        curr->next->prev= newNode;
        curr->next= newNode;
    }

    //deletion
    void deletionAtHead(){
        if(head==NULL){
            cout<<"List is Empty!"<<endl;
            return;
        }
        Node *temp= head;
        head= head->next;
        head->prev= NULL;
        delete temp;
    }

    void deletionAtTail(){
        if(head==NULL){
            cout<<"List is Empty!"<<endl;
            return;
        }
        Node *temp= tail;
        tail= tail->prev;
        tail->next= NULL;
        delete temp;
    }

    void deletionAt(int pos){
        if(pos<1){
            cout<<"Invalid Position!"<<endl;
            return;
        }
        if(pos==1){
            return deletionAtHead();
        }
        int count= 1;
        Node *curr= head;
        while(curr!=NULL && count<pos){
            curr= curr->next;
            count++;
        }
        if(curr==NULL){
            cout<<"Invalid Position!"<<endl;
            return;
        }
        Node *prevCurr= curr->prev;
        prevCurr->next= curr->next;
        if(curr->next!=NULL){
            curr->next->prev = prevCurr;
        }
        else{
            tail=prevCurr;
        }
        delete curr;
    }

    //print
    void print(){
        Node *curr= head;
        while(curr){
        cout<<curr->data<<"<-->";
        curr= curr->next;
    }
    cout<<"null"<<endl;
    }
};
int main()
{
    // Node *head = new Node(10);
    // Node *node1= new Node(11);
    // Node *node2= new Node(12);
    // Node *node3= new Node(13);

    // head->next = node1;
    // node1->prev= head;
    // node1->next= node2;
    // node2->prev= node1;
    // node2->next= node3;
    // node3->prev= node2;

    // Node *curr= head;
    //     while(curr){
    //     cout<<curr->data<<"<-->";
    //     curr= curr->next;
    // }
    // cout<<"null";

    DoubleyLI ob;
    ob.insertAtHead(11);
    ob.insertAtTail(12);
    ob.insertAtTail(13);
    ob.insertAtTail(14);
    ob.insertAtHead(10);
    ob.insertAtTail(15);
    ob.print();
    ob.insertAt(25,2);
    ob.print();
    ob.deletionAtHead();
    ob.print();
    ob.deletionAtTail();
    ob.print();
    ob.deletionAt(3);
    ob.print();
return 0;
}