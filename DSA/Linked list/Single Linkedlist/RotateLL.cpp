#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data =val;
        next =NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void insertEnd(int val){
        Node* newNode = new Node(val);
        if (head ==NULL){
            head =newNode;
            return;
        }
        Node* temp =head;
        while (temp->next !=NULL) {
            temp =temp->next;
        }
        temp->next =newNode;
    }

    void printList(){
        Node* temp =head;
        while (temp!= NULL) {
            cout <<temp->data<<" ";
            temp =temp->next;
        }
        cout<<endl;
    }

    Node* findNthNode(Node* temp,int k){
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp= temp->next;   
        }
        return temp;
    }
    
    void rotateLL(int k){
        if(head==NULL || k==0) return;
        Node* tail= head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail= tail->next;
        }

        if(k%len==0) return;
        k= k%len;

        //attach the tail to head
        tail->next= head;
        Node* newLastNode= findNthNode(head,len-k);

        head= newLastNode->next;
        newLastNode->next= NULL;
    }
};

int main(){
    LinkedList ll;
    int n,k;
    cin >>n>>k;
    for (int i= 0;i <n;i++) {
        int val;
        cin >> val;
        ll.insertEnd(val);
    }
    ll.rotateLL(k);
    ll.printList();

    return 0;
}
