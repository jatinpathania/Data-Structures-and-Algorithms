#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList(){
        head=NULL;
    }

    void insertEnd(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head= newNode;
            return;
        }
        Node* temp= head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next= newNode;
        newNode->prev= temp;
    }

    void deleteAllOccurrences(int key){
        Node* temp= head;
        while(temp!=NULL){
            if(temp->data==key){
                //check if head is key or not
                if(temp==head){
                    head= head->next;
                    if(head!=NULL) head->prev=NULL;
                }
                Node* nextNode= temp->next;
                Node* prevNode= temp->prev;
                if(nextNode) nextNode->prev= prevNode;
                if(prevNode) prevNode->next= nextNode;
                delete temp;
                temp= nextNode;
            }
            else{
                temp= temp->next;
            }
        }
    }

    void printList(){
        Node* temp= head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyLinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(20);
    list.insertEnd(40);
    list.insertEnd(20);

    int key=20;
    list.deleteAllOccurrences(key);

    list.printList();
    return 0;
}
