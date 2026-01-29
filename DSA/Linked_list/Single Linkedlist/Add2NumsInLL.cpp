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
    Node* addTwoLists(Node* l1,Node* l2){
        Node* temp1= l1;
        Node* temp2= l2;
        Node* dummyNode= new Node(-1);
        Node* curr= dummyNode;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum=carry;
            if(temp1) sum=sum+ temp1->data;
            if(temp2) sum=sum+ temp2->data;
            Node* newNode= new Node(sum%10);
            carry= sum/10;
            curr->next= newNode;
            curr= newNode;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(carry){
            Node* newNode= new Node(carry);
            curr->next= newNode;
            curr= newNode;
        }
        Node* head= dummyNode->next;
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
    Node* l1=new Node(2);
    l1->next=new Node(4);
    l1->next->next=new Node(3);

    Node* l2=new Node(5);
    l2->next=new Node(6);
    l2->next->next=new Node(4);

    Solution obj;
    Node* result=obj.addTwoLists(l1,l2);

    printList(result);
    return 0;
}
