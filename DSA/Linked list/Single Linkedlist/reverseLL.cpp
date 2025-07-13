#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void reverseList() {
        Node* curr = head;
        Node* prev = NULL;
        Node* temp;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }
    
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    
    cout << "Original List: ";
    list.printList();
    
    list.reverseList();
    cout << "Reversed List: ";
    list.printList();
    
    return 0;
}


//                      RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// class ListNode {
// public:
//     int val;
//     ListNode* next;
    
//     ListNode(int x) : val(x), next(NULL) {}
// };


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL || head->next == NULL) return head;
        
//         ListNode* newNode = reverseList(head->next);
//         ListNode* front = head->next;
//         front->next = head;
//         head->next = NULL;
        
//         return newNode;
//     }
// };


// void insert(ListNode*& head, int val) {
//     if (head == NULL) {
//         head = new ListNode(val);
//         return;
//     }
//     ListNode* temp = head;
//     while (temp->next) temp = temp->next;
//     temp->next = new ListNode(val);
// }


// void printList(ListNode* head) {
//     while (head) {
//         cout << head->val << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// int main() {
//     ListNode* head = NULL;

//     insert(head, 1);
//     insert(head, 2);
//     insert(head, 3);
//     insert(head, 4);
//     insert(head, 5);

//     cout << "Original List: ";
//     printList(head);

//     Solution sol;
//     head = sol.reverseList(head);

//     cout << "Reversed List: ";
//     printList(head);

//     return 0;
// }
