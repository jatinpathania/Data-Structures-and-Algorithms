#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool isSymmetricUtil(Node* left, Node* right){
        if(left==NULL || right==NULL){
            return left==right;
        }
        if(left->data != right->data) return false;

        return isSymmetricUtil(left->left, right->right) && isSymmetricUtil(left->right, right->left);
    }

public:
    bool isSymmetric(Node* root) {
        return root==NULL || isSymmetricUtil(root->left, root->right);
    }
};
void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;
    cout << "Binary Tree (Inorder):";
    printInorder(root);
    cout << endl;
    bool res;
    res = solution.isSymmetric(root);
    if(res){
        cout << "This Tree is Symmetrical" << endl;
    }
    else{
        cout << "This Tree is NOT Symmetrical" << endl;
    }
    return 0;
}