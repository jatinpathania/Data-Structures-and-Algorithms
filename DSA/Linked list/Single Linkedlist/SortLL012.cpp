#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val){
        data= val;
        next= nullptr;
    }
};
class Solution{
public:
    // this takes O(2N) 
    // Node* sortList(Node* head) {
    //     Node* temp=head;
    //     int cnt0=0,cnt1=0,cnt2=0;
    //     while(temp!=NULL){
    //         if(temp->data==0) cnt0++;
    //         else if(temp->data==1) cnt1++;
    //         else cnt2++;
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     while(temp!=NULL){
    //         if(cnt0){
    //             temp->data=0;
    //             cnt0--;
    //         }
    //         else if(cnt1){
    //             temp->data=1;
    //             cnt1--;
    //         }
    //         else{
    //             temp->data=2;
    //             cnt2--;
    //         }
    //         temp=temp->next;
    //     }
    //     return head;
    // }


    // O(N) time complexity
    Node* sortList(Node* head){
        if(head==NULL || head->next==NULL) return head;
        Node* zeroHead= new Node(-1);
        Node* zero= zeroHead;
        Node* oneHead= new Node(-1);
        Node* one= oneHead;
        Node* twoHead= new Node(-1);
        Node* two= twoHead;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one= one->next;
            }
            else{
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        zero->next= (oneHead->next)? oneHead->next : twoHead->next;
        one->next= twoHead->next;
        two->next= NULL;
        Node* newHead= zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }
};

void printList(Node* head) {
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main() {
    Node* head= new Node(2);
    head->next= new Node(1);
    head->next->next=new Node(0);
    head->next->next->next= new Node(1);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(0);

    cout<<"Original list: ";
    printList(head);

    Solution sol;
    head=sol.sortList(head);

    cout<<"Sorted list: ";
    printList(head);

    return 0;
}
