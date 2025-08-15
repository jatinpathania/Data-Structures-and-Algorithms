#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // int findMin(TreeNode* root) {
    //     if(root==NULL) return -1;
    //     while(root->left!=NULL){
    //         root= root->left;
    //     }
    //     return root->val;
    // }

    // int findMax(TreeNode* root) {
    //     if(root==NULL) return -1;
    //     while(root->right!=NULL){
    //         root= root->right;
    //     }
    //     return root->val;
    // }

    // Recursive solutions for these

    int findMin(TreeNode* root) {
        if(root==NULL) return -1;
        
        if(root->left==NULL) return root->val;
        return findMin(root->left);
    }

    int findMax(TreeNode* root) {
        if(root==NULL) return -1;
        
        if(root->right==NULL) return root->val;
        return findMax(root->right);
    }
};

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    int minimum = solution.findMin(root);
    int maximum = solution.findMax(root);

    cout << "Minimum value in the tree: " << minimum << endl;
    cout << "Maximum value in the tree: " << maximum << endl;

    return 0;
}