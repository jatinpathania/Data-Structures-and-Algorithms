// Given that the linked list is sorted already
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList(){
        head=NULL;
    }

    void insertEnd(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head= newNode;
            return;
        }
        Node* temp= head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next= newNode;
        newNode->prev= temp;
    }

    void findPairsWithSum(int target){
        if(head==NULL) return ;
        vector<pair<int,int>> res;
        Node* left= head;
        Node* right= head;
        while(right->next!=NULL){
            right= right->next;
        }

        while(left->data< right->data){
            if(left->data+ right->data==target){
                res.push_back({left->data,right->data});
                left= left->next;
                right= right->prev;
            }
            else if(left->data+right->data< target){
                left= left->next;
            }
            else right= right->prev;
        }

        if(res.empty()){
            cout<<"No pair found!";
            return;
        }
        // print
        for(auto num : res){
            cout<<"{"<<num.first<<","<<num.second<<"}"<<endl;
        }
    }

    void display(){
        Node* temp= head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertEnd(1);
    dll.insertEnd(2);
    dll.insertEnd(3);
    dll.insertEnd(4);
    dll.insertEnd(5);

    dll.display();

    int sum=5;
    dll.findPairsWithSum(sum);

    return 0;
}
