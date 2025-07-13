#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev= slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next= slow->next;
        delete slow;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* newHead = sol.deleteMiddle(head);

    ListNode* temp = newHead;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
