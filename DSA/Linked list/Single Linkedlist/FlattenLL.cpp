//Brute force
// I will take the temp for head first and an empty array and also a t2 pointer which initally is at temp of ll ...now using condition till temp is not null.. i will traverse and also while traversing use while loop i.e till t2 is not null.. add t2 in array  and then move to the next .. in this way whole linked list is added in array . Now we can use any sorting algo to sort the array and then make a vertical linked list from that

// Optimal code

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

Node* merge(Node* list1,Node* list2){
    Node* dummyNode= new Node(-1);
    Node* temp= dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            temp->child= list1;
            temp= list1;
            list1= list1->child;
        }
        else{
            temp->child= list2;
            temp= list2;
            list2= list2->child;
        }
        temp->next=NULL;
    }
    if(list1) temp->child= list1;
    else temp->child= list2;
    if(dummyNode->child) dummyNode->child->next=NULL;
    return dummyNode->child;
}

Node* flatten(Node* head) {
    if(head==NULL || head->next==NULL) return head;
    Node* mergedHead= flatten(head->next);
    head= merge(head,mergedHead);
    return head;
}

void printList(Node* head) {
    while(head){
        cout<<head->data<<" ";
        head =head->child;
    }
    cout<<endl;
}

int main() {
    // Level 0
    Node* n3 = new Node(3);
    Node* n2 = new Node(2);
    Node* n1 = new Node(1);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    
    n3->next = n2;
    n2->next = n1;
    n1->next = n4;
    n4->next = n5;

    // Level 1
    n2->child = new Node(10);
    n1->child = new Node(7);
    n4->child = new Node(9);
    n5->child = new Node(6);

    // Level 2
    n1->child->child = new Node(11);
    n5->child->child = new Node(8);

    // Level 3
    n1->child->child->child = new Node(12);

    Node* head = n3;
    cout<<"Flattened list: ";
    Node* flatHead =flatten(head);
    printList(flatHead);
    return 0;
}
