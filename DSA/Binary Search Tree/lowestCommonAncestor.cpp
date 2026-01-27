#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Time Complexity: O(h)
// Space Complexity: O(h)

int lowestCommonAncestor(Node* root, int k1, int k2){
    if(root==NULL) return -1;
    if(k1 < root->data && k2 < root->data) return lowestCommonAncestor(root->left , k1, k2);
    if(k1 > root->data && k2 > root->data) return lowestCommonAncestor(root->right, k1, k2);
    return root->data;
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    int k1 = 5;
    int k2 = 15;
    cout << lowestCommonAncestor(root, k1, k2);
    return 0;
}