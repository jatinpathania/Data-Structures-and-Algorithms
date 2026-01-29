// For generic code.. we can take a hasmap and the pseudo code can be like this
//temp= head
// map<node,node> mpp;
// while(temp!=NULL){
//     node newndoe= new node(temp->val)
//     mpp[temp]= newnode;
//     temp= temp->next;
// }
// temp= head
// while(temp!=NULL){
//     copiednode=  mpp[temp]
//     copynode->next= mpp[temp->next]
//     copynode->random= mpp[temp->random]
//     temp= temp->next
// }
// return mpp[head]

// But this code will take O(2N) time and O(2N) complexity 

// Optimal code

// steps
// 1. insert copiednode in between
// 2. connect random pointers
// 3. connect next pointers



#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* random;
        Node(int val){
            data =val;
            next =NULL;
            random= NULL;
        }
};

void insertCopyInBetween(Node* head){
    Node* temp= head;
    while(temp!= NULL){
        Node* nextElement= temp->next;
        Node* copyNode= new Node(temp->data);
        copyNode->next=nextElement;
        temp->next= copyNode;
        temp= nextElement;
    }
}
void connectRandomPointers(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        Node* copyNode= temp->next;
        if(temp->random){
            copyNode->random= temp->random->next;        // imagine this line in diagram
        }else{
            copyNode->random= NULL;
        }
        temp= temp->next->next;
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp= head;
    Node* dummyNode= new Node(-1);
    Node* res= dummyNode;
    while(temp!=NULL){
        //creating new list
        res->next= temp->next;
        res= res->next;
        //disconnecting and going back
        temp->next=temp->next->next;
        temp= temp->next;
    }
    return dummyNode->next;
}

Node* cloneList(Node* head){
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}

void printList(Node* head){
    Node* temp =head;
    while (temp !=NULL) {
        cout<<"Node: "<<temp->data;
        cout << ", Random: ";
        if(temp->random)
            cout<<temp->random->data;
        else
            cout << "NULL";
        cout<<endl;
        temp= temp->next;
    }
}
int main(){
    Node* node1 =new Node(7);
    Node* node2 =new Node(13);
    Node* node3 =new Node(11);
    Node* node4 =new Node(10);
    Node* node5 =new Node(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1->random= NULL;
    node2->random= node1;
    node3->random= node5;
    node4->random= node3;
    node5->random= node1;

    cout <<"Original list:\n";
    printList(node1);

    Node* clonedHead = cloneList(node1);
    cout << "\nCloned list:\n";
    printList(clonedHead);
    return 0;
}
