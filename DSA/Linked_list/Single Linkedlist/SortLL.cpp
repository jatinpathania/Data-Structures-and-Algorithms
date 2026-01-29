#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int x):data(x),next(NULL){}
};

class Solution{
public:
    ListNode* mergeLists(ListNode* list1,ListNode* list2){
        ListNode* dummyNode= new ListNode(-1);
        ListNode* temp= dummyNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->data< list2->data){
                temp->next= list1;
                temp=list1;
                list1= list1->next;
            }
            else{
                temp->next= list2;
                temp= list2;
                list2= list2->next;
            }
        }
        if(list1) temp->next= list1;        // this adds the remaining full list so no need for while loop
        else if(list2) temp->next= list2;
        return dummyNode->next;
    }
    
    ListNode* findMiddle(ListNode* head){
        ListNode* slow= head;
        ListNode* fast= head->next;        //this is because we want the middle to stop one step before the middle
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle= findMiddle(head);
        ListNode* right=middle->next;
        middle->next= NULL;
        ListNode* left= head;
        left= sortList(left);
        right= sortList(right);
        return mergeLists(left,right);
    }
};

int main(){
    ListNode* head= new ListNode(4);
    head->next= new ListNode(2);
    head->next->next= new ListNode(1);
    head->next->next->next= new ListNode(3);

    Solution sol;
    ListNode* newHead= sol.sortList(head);

    ListNode* temp= newHead;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}
