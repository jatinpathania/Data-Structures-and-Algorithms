#include <bits/stdc++.h>
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
    // First method - through hashmap
    // Node* getIntersectionNode(Node* headA,Node* headB){
    //     unordered_map<Node*,int> mpp;
    //     Node* temp1= headA;
    //     while(temp1!=NULL){
    //         mpp[temp1]=1;
    //         temp1=temp1->next;
    //     }
    //     Node* temp2= headB;
    //     while(temp2!=NULL){
    //         if(mpp.find(temp2)!=mpp.end()) return temp2;
    //         temp2= temp2->next;
    //     }
    //     return NULL;
    // }

    // Method 2
    // Node* collisionPoint(Node* head1, Node* head2,int n){
    //     while(n){
    //         n--;
    //         head2= head2->next;
    //     }
    //     while(head1!=head2){
    //         head1= head1->next;
    //         head2= head2->next;
    //     }
    //     return head1;
    // }
    // Node* getIntersectionNode(Node* headA,Node* headB) {
    //     int cnt1=0,cnt2=0;
    //     Node* temp1= headA;
    //     while(temp1!=NULL){
    //         cnt1++;
    //         temp1= temp1->next;
    //     }
    //     Node* temp2= headB;
    //     while(temp2!=NULL){
    //         cnt2++;
    //         temp2= temp2->next;
    //     }
    //     if(cnt1< cnt2){
    //         return collisionPoint(headA,headB,cnt2-cnt1);  // smaller first then bigger one
    //     }
    //     else{
    //         return collisionPoint(headB,headA, cnt1-cnt2);
    //     }
    //     return NULL;
    // }


    // Method 3  (Optimal)
    Node* getIntersectionNode(Node* headA,Node* headB) {
        if(headA==NULL || headB==NULL) return NULL;
        Node* temp1= headA;
        Node* temp2= headB;
        while(temp1!=temp2){
            if(temp1!=NULL){
                temp1= temp1->next;
            }else{
                temp1=headB;
            }
            
            if(temp2!=NULL){
                temp2= temp2->next;
            }else{
                temp2= headA;
            }
        } 
        return temp1;
    }
};

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main(){
    Node* common=new Node(3);
    common->next=new Node(4);
    common->next->next=new Node(5);

    Node* headA=new Node(1);
    headA->next=new Node(2);
    headA->next->next=common;

    Node* headB=new Node(9);
    headB->next=new Node(10);
    headB->next->next=common;

    Solution sol;
    Node* intersection=sol.getIntersectionNode(headA, headB);

    if(intersection!=NULL){
        cout<<"Intersection at node with value: "<<intersection->data<<"\n";
    }
    else{
        cout<<"No intersection found.\n";
    }

    return 0;
}
