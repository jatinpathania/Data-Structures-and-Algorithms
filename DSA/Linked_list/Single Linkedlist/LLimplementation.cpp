#include <iostream>
using namespace std;
class myNode{
    public:
    int data;
    myNode* next;
    //constructor
    myNode(int data){
        this->data = data;
        next = nullptr;
    }
};

class myLinkedList{
    public:
    myNode* head =nullptr;
    
    void insertAtHead(int data){
        myNode* newNode = new myNode(data);
        newNode->next=head;
        head = newNode;
    }

    void insertAtTail(int data){
        myNode* newNode = new myNode(data);

        //if linkedlist is empty
        if(head==nullptr){
            head = newNode;
        }

        //if only one node
        if(head->next== nullptr){
            head->next = newNode;
        }

        //traverse to last node and stop at last
        myNode* curr= head;
        while(curr->next!=nullptr){               //this is because next of lastnode is nullptr ..so we will go till there
            curr= curr->next;
        }
        curr->next = newNode;
    }

    //insert after pos
    void insertAfterPos(int data, int pos){
        if(pos<1){
            cout<<"invalid pos";
            return;
        }
        if(pos==1){
            return insertAtHead(data);
        }
        myNode* newNode = new myNode(data);

        //traverse to given pos
        myNode* curr= head;
        int count = 1;
        while(curr!=nullptr && count<pos-1){                   //we will stop at pos
            curr = curr->next;
            count++;
        }
        if(curr==NULL){
            cout<<"invalid pos"<<endl;
            delete newNode;
            return;
        }
        newNode->next = curr->next;
        curr->next= newNode;
    }

    //deletion at head
    void deleteAtHead(){
        if(head==nullptr){
            cout<<"list is empty"<<endl;
            return;
        }
        myNode* temp = head;
        head = head->next;
        delete temp;
    }

    //deletion at last
    void deleteAtLast(){
        if(head==NULL || head->next==NULL) return ;
        myNode* secondLast= head;
        while(secondLast->next->next!=nullptr){
            secondLast= secondLast->next;
        }
        delete secondLast->next;
        secondLast->next=NULL;
    }

    //deletion at particular position
    void deleteAtPos(int pos){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        if(pos==1){
            //simply call deleteAtHead() or
            myNode* temp= head;
            head = head->next;
            delete temp;
            return;
        }
        int count=0;
        myNode* temp= head;
        myNode* prev=NULL;
        while(temp!=NULL){
            count++;
            if(count==pos){
                prev->next= prev->next->next;
                delete temp;
                break;
            }
            prev= temp;
            temp= temp->next;
        }
        return;
    }

    //print the linkedlist
    void printList(){
        myNode* curr= head;
        while(curr!=nullptr){
            cout<<curr->data<<"->";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    //creating a linkedList
    // myNode* first= new myNode(5);
    // myNode* second= new myNode(7);
    // myNode* third= new myNode(9);
    // first->next = second;
    // second-> next= third;

    myLinkedList list;
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.printList();
    // list.deleteAtHead();
    // list.deleteAtLast();
    // list.printList();
    // list.deleteAtPos(2);
    // list.printList();
    list.insertAfterPos(69,3);
    list.printList();
return 0;
}