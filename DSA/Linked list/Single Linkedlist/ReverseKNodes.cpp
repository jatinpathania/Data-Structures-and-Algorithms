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


    Node* reverseLL(Node* temp){          //changing original ll as reference is passed
        Node* prev=NULL;
        Node* curr= temp;
        while(curr!=NULL){
            Node* nextNode= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextNode;
        }
        return prev;
    }
    
    Node* findKthNode(Node* temp,int k){
        k= k-1;                  // coz we take as index 0
        while(temp!=NULL && k>0){
            k--;
            temp= temp->next;
        }
        return temp;
    }

    void reverseKGroup(int k){
        Node* temp= head;
        Node* prevLast= NULL;
        while(temp!=NULL){
            Node* kthNode= findKthNode(temp,k);
            if(kthNode==NULL){
                if(prevLast) prevLast->next= temp;
                break;
            }
            Node* nextNode= kthNode->next;
            kthNode->next= NULL;
            Node* newHead= reverseLL(temp);
            if(temp==head){
                head= newHead;
            }
            else{
                prevLast->next= newHead;
            }
            prevLast= temp;
            temp= nextNode;
        }
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
    ll.reverseKGroup(k);
    ll.printList();

    return 0;
}
