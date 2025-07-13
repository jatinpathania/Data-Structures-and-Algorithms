#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next= nullptr;        // we create it in public so that next and data is accessible through whole code

    Node(int data){
        this->data= data;
    }
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
};



Node* convertarrtoLL(vector<int> &arr){   // we can't return whole linked list that's why return a pointer to the head of the LL
    Node* head = new Node(arr[0]);
    Node* mover= head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}

int checkifPresent(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp= temp->next;
    }
    return 0;
}

                //DELETIONS

Node* removeHead(Node* head){
    //checking empty LL
    if(head== NULL) return head;
    Node* temp= head;
    head= head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    //checking single element
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp= head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next= NULL;      //this is where LL stops after tail deletion
    return head;
}

Node* deleteAtPos(Node* head,int pos){
    if(head==NULL) return head;
    if(pos==1){
        //simply call removeHead() or
        Node* temp= head;
        head = head->next;
        delete temp;
        return head;
    }
    if(pos>lengthOfLL(head)){
        cout<<"Position does not exist"<<endl;
        return head;
    }
    int count=0;
    Node* temp= head;
    Node* prev= NULL;
    while(temp!=NULL){
        count++;
        if(count==pos){
            prev->next= prev->next->next;
            delete temp;
            break;
        } 
        prev = temp;
        temp= temp->next;
    }
    return head;
}


//delete at val
Node* deleteEL(Node* head,int ele){
    if(head==NULL) return head;
    if(head->data==ele){
        //simply call removeHead() or
        Node* temp= head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp= head;
    Node* prev= NULL;
    while(temp!=NULL){
        if(temp->data==ele){
            prev->next= prev->next->next;
            delete temp;
            break;
        } 
        prev = temp;
        temp= temp->next;
    }
    return head;
}

            //INSERTIONS

Node* insertHead(Node* head,int ele){
    Node* newNode = new Node(ele,head);       //constructer
    return newNode;
}

Node* insertTail(Node* head,int ele){
    Node* newNode= new Node(ele);
    if(head==NULL) return newNode;   //if no head.then simply insert newNode to it
    Node* temp= head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= newNode;
    return head;
}

Node* insertAtPos(Node* head,int ele,int pos){ 
    if(head==NULL){
        if(pos==1)return new Node(ele);
        else return head;
    }
    if(pos==1){
        Node* newNode = new Node(ele,head);
        return newNode;
    }
    //if we are going to fill
    int count=0;
    Node* temp= head;
    while(temp!=NULL){
        count++;
        if(count==pos-1){
            Node* newNode= new Node(ele);
            // first connect before breaking the links
            newNode->next= temp->next;
            temp->next= newNode;
            break;
        }
        temp= temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head,int ele,int val){ 
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        Node* newNode = new Node(ele,head);
        return newNode;
    }
    Node* temp= head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* newNode= new Node(ele);
            // first connect before breaking the links
            newNode->next= temp->next;
            temp->next= newNode;
            break;
        }
        temp= temp->next;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    //converting an array to LL
    vector<int> arr={1,5,32,2,18,6,7,4,19};  
    Node* head= convertarrtoLL(arr);
    cout<<head->data<<endl;

    //traversing a LL
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp= temp->next;
    }

    //length of LL
    int len= lengthOfLL(head);
    cout<<endl<<"Length of LL is: "<<len<<endl;

    //search for element
    if(checkifPresent(head,15)) cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;

    //printing a LL
    cout<<"The linked list is:";
    print(head);
    cout<<endl;

    //removing head
    cout<<"The linked list after removing head is: ";
    head= removeHead(head);
    print(head);

    //removing tail
    cout<<"The linked list after removing tail is: ";
    head= removeTail(head);
    print(head);

    //removing at a position
    cout<<"The linked list after removing the given pos is: ";
    head= deleteAtPos(head,2);
    print(head);

    //delete data
    cout<<"The linked list after removing the element is: ";
    head= deleteEL(head,6);
    print(head);

    //insert head
    cout<<"The linked list after adding new head is: ";
    head= insertHead(head,99);
    print(head);

    //insert tail
    cout<<"The linked list after adding new tail is: ";
    head= insertTail(head,88);
    print(head);

    //insert at a particular position
    cout<<"The linked list after adding at given pos is: ";
    head= insertAtPos(head,69,3);
    print(head);

    //insert before a particular value
    cout<<"The linked list after adding before the given value is: ";
    head= insertBeforeValue(head,150,69);
    print(head);
return 0;
}