//first approach is reverse then add 1 and then check if still carry left.. create new node and firstly reverse and then add newnode to head and
// if there is no carry .. then simply reverse the ll and return
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Solution{
public:
    int helper(Node* temp){
        if(temp==NULL) return 1;
        int carry= helper(temp->next);
        temp->data= temp->data+carry;
        if(temp->data<10){
            return 0;
        }
        temp->data=0;
        return 1;
    }

    Node* addOne(Node* head){
        if(head==NULL || head->next==NULL) return NULL;
        int carry= helper(head);
        if(carry==1){
            Node* newNode= new Node(carry);
            newNode->next= head;
            head= newNode;
            return head;
        }
        return head;
    }
};

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(9);
    head->next->next=new Node(9);

    Solution obj;
    head=obj.addOne(head);

    printList(head);
    return 0;
}
