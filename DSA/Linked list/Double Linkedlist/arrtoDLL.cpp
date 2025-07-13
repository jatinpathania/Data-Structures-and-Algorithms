#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1){
        data= data1;
        next = NULL;
        back = NULL;
    }
    Node(int data1,Node *next1,Node* back1){
        data=data1;
        next=next1;
        back= back1;
    }
};

Node* convertarrtoDLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* prev= head;
    for(int i=1 ;i<arr.size() ;i++){
        Node* temp= new Node(arr[i],NULL,prev);
        prev->next= temp;
        temp->back=prev;
        prev= temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* prev= head;
    head= head->next;
    head->back=NULL;
    prev->next=NULL;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL ||head->next==NULL) return NULL;
    Node* tail=head;
    while(tail->next!=NULL){
        tail= tail->next;
    }
    Node* prev= tail->back;
    prev->next=NULL;
    tail->back= NULL;
    delete tail;
    return head;
}

Node* deleteKthNode(Node* head,int k){
    if(head==NULL) return NULL;
    //firstly we travel till the kth node
    int count=0;
    Node* temp= head;
    while(temp!=NULL){
        count++;
        if(count==k) break;
        temp= temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;

    //edge cases
    //if there is only one node
    if(prev==NULL && front==NULL){
        return NULL;
    }
    //if prev is NULL
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    //finally deleting temp..we stand currently at temp
    prev->next= front;
    front->back= prev;
    temp->back=NULL;
    temp->next=NULL;
    delete temp;
    return head;
}

void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=NULL;
        temp->back=NULL;
        delete(temp);
        return;
    }

    prev->next=front;
    front->back=prev;
    temp->back=NULL;
    temp->next=NULL;
    delete temp;
}

Node* insertBeforeHead(Node* head,int val){
    Node* temp=new Node(val,head,NULL);
    head->back=temp;
    head=temp;
    return head;
}

Node* insertBeforeTail(Node* head,int val){
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode=new Node(val,tail,NULL);
    prev->next=newNode;
    tail->back=newNode;
    newNode->back=prev;
    return head;
}

Node* insertAfterPos(Node* head,int val,int pos){
    if(pos==1) return insertBeforeHead(head,val);
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        if(count==pos)break;
        temp=temp->next;
    }
    Node* prev= temp->back;
    Node* newNode= new Node(val,temp,prev);
    temp->back=newNode;
    prev->next=newNode;
    return head;
}

void insertBeforeNode(Node* node,int val){
    Node* prev= node->back;
    Node* newNode= new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
    return;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    vector<int> arr= {1,2,3,4,5,6,7,8};
    Node *head= convertarrtoDLL(arr);
    print(head);

    // deleting head
    cout<<"The DLL after deleting the head is: ";
    head= deleteHead(head);
    print(head);

    //deleting tail
    cout<<"The DLL after deleting the tail is: ";
    head= deleteTail(head);
    print(head);

    //deleting kthNode
    cout<<"The DLL after deleting the kth node is: ";
    head= deleteKthNode(head,4);
    print(head);

    //deleting a node
    cout<<"The DLL after deleting a node passed is: ";
    deleteNode(head->next->next);           //it can never be head
    print(head);

    //inserting before head
    cout<<"The DLL after inserting before the head: ";
    head= insertBeforeHead(head,1);
    print(head);

    //inserting before tail
    cout<<"The DLL after inserting before the tail: ";
    head= insertBeforeTail(head,8);
    print(head);

    // inserting after a given pos
    cout<<"The DLL after inserting after a given pos is: ";
    head= insertAfterPos(head,9,3);
    print(head);

    //inserting before Node
    cout<<"The DLL after inserting before a node is: ";
    insertBeforeNode(head->next->next,10);
    print(head);
    return 0;
}
