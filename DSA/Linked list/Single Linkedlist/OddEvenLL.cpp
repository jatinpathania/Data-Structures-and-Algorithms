//we can do this code by taking an array and storing the ll eles in that odd first and then even. Then finally, we can just change the ll data
//through traversing the array and ll together and that's how we can arrange ll first odd and then even
// space complexity  O(n)   Time complexity-  O(n/2)+ O(n/2)= O (n)

//optimal

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* segregateOddEven(ListNode* head){
        if(head==NULL  || head->next==NULL) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead= head->next;      // never forget it.. this is the most imp thing for joining the LL's below

        // no need for odd .. coz odd is always behind the even so if even hasn't reached the end nor the odd 
        while(even!=NULL && even->next!=NULL){
            odd->next= odd->next->next;
            even->next= even->next->next;

            odd= odd->next;
            even= even->next;
        }
        odd->next=evenHead;
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
    ListNode* newHead = sol.segregateOddEven(head);

    ListNode* temp = newHead;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
