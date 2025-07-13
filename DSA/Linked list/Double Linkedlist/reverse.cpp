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
        prev= temp;
    }
    return head;
}

Node* reverseDLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* last =NULL;
    Node* temp= head;
    while(temp!=NULL){
        //swapping to change the links
        last= temp->back;
        temp->back=temp->next;
        temp->next=last;
        temp=temp->back;
    }
    //finally making the last node as new head
    head= last->back;
    return  head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    // we can reverse DLL through brute force by using stack
    // first put all elements in stack then pop one by one and store in DLL 
    // but this is gonna take O(2n) time complexity 

    // Optimal approach is changing the links
    vector<int> arr= {1,2,3,4,5,6,7,8};
    Node *head= convertarrtoDLL(arr);
    print(head);

    head= reverseDLL(head);
    print(head);
return 0;
}