#include <iostream>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool validate(TreeNode* root, long min, long max){
        if(root==NULL) return true;
        if(root->val <=min || root->val >=max) return false;

        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root){
         return validate(root, LONG_MIN, LONG_MAX);
    }
};
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    /*
        Constructing the following example:
                   5
                  / \
                 2   7
                    / \
                   6   8
    */

    TreeNode* root = new TreeNode(5);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(7);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << "Tree (inorder traversal): ";
    printInOrder(root);
    cout << endl;

    Solution sol;
    if(sol.isValidBST(root)){
        cout << "This is a valid Binary Search Tree." << endl;
    } else {
        cout << "This is NOT a valid Binary Search Tree." << endl;
    }
    return 0;
}