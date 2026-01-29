#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next= nullptr;

    Node(int data){
        this->data= data;
    }
    Node(int data1,Node *next){
        data=data1;
        this->next=next;
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

Node* middleOfLL(Node* head){
    // in case of LL of odd length ... fast pointer reaches the end while in case of LL of even length.. it never reaches end so it reaches NULL
    Node* slow= head;
    Node* fast= head;
    while(fast!= NULL && fast->next!=NULL){  // 1st condition is for even and 2nd for odd len LL
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}

bool checkLoop(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!= NULL && fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main()
{
    vector<int> arr={1,5,32,2,18,6,7,4,19};  
    Node* head= convertarrtoLL(arr);

    //finding middle
    // using formula (only if n is given)
    // int n= arr.size();
    // int mid = (n/2)+1;
    // cout<<mid;

    // if n is not given.. we can use traversal to find the length of LL using count variablea and then decreasing mid till it reaches 0
    // so it traverses till mid but still this is not optimal solution
    // time complexity is( O(n)+O(n/2))


    //                                  (optimal solution)
    // using slow pointer approach ( tortoise and hare)
    head= middleOfLL(head);
    cout<<head->data<<endl;

    // checking loop
    if(checkLoop(head)){
        cout<<"loop exists";
    }
    else{
        cout<<"no loop exists";
    }

return 0;
}