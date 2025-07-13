#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int findLen(ListNode* slow,ListNode* fast){
        int count=0;
        fast=fast->next;
        while(fast!=slow){
            count++;
            fast=fast->next;
        }
        return count;
    }
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return findLen(slow,fast);
            }
        }
        return 0;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 

    Solution sol;
    int loopLength = sol.findLengthOfLoop(head);
    if (loopLength)
        cout << "Length of the loop is: " << loopLength << endl;
    else
        cout << "No loop detected" << endl;

    return 0;
}
