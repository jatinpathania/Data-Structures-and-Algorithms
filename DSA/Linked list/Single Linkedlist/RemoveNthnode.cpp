#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // this code takes O(n)+ O(len-n)
    // ListNode* removeNthFromEnd(ListNode* head, int n){
    //     int count=0;
    //     ListNode* temp=head;
    //     while(temp!=nullptr){
    //         count++;
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     if(count==n){           // simply delte the head
    //         ListNode* newHead=head->next;
    //         free(head);
    //         return newHead;
    //     }
    //     int res= count-n;   
    //     temp=head;
    //     while(temp!=NULL){
    //         res--;
    //         if(res==0) break;
    //         temp=temp->next;
    //     }
    //     //now deleting the node
    //     ListNode* delNode= temp->next;
    //     temp->next=temp->next->next;
    //     free(delNode);
    //     return head;
    // }

    //Optimal
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* fast=head;
        for(int i=0 ;i<n ;i++){
            fast=fast->next;
        }
        ListNode* slow=head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        if(fast==NULL) return head->next;     //coz that simply means delete the head
        ListNode* delNode= slow->next;
        slow->next=slow->next->next;
        free(delNode);
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution sol;
    ListNode* newHead = sol.removeNthFromEnd(head, n);

    ListNode* temp = newHead;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
