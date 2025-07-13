#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data=val;
        next=NULL;
    }
};

void insertEnd(Node** head, int data) {
    Node* newNode=new Node(data);
    if (*head==NULL) {
        *head=newNode;
        return;
    }
    Node* temp=*head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

struct Node* intersection(struct Node* head1, struct Node* head2) {
    if (head1==nullptr || head2==nullptr) return nullptr;

    vector<int> arr1, arr2, res;

    Node* temp1=head1;
    while (temp1!=nullptr) {
        arr1.push_back(temp1->data);
        temp1=temp1->next;
    }

    Node* temp2=head2;
    while (temp2!=nullptr) {
        arr2.push_back(temp2->data);
        temp2=temp2->next;
    }

    for (int i=0; i<arr1.size(); i++) {
        for (int j=0; j<arr2.size(); j++) {
            if (arr1[i]==arr2[j]) {
                res.push_back(arr1[i]);
                break;
            }
        }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    Node* head3=NULL;
    for (int val: res) {
        insertEnd(&head3, val);
    }

    return head3;
}

void printList(Node* head) {
    while (head!=NULL) {
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

int main() {
    Node* head1=NULL;
    Node* head2=NULL;

    insertEnd(&head1, 10);
    insertEnd(&head1, 20);
    insertEnd(&head1, 30);

    insertEnd(&head2, 20);
    insertEnd(&head2, 40);
    insertEnd(&head2, 30);

    Node* head3=intersection(head1, head2);

    cout << "Intersection: ";
    printList(head3);

    return 0;
}
