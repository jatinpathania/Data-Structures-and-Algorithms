#include <iostream>
#include <stack>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal(TreeNode* root) {
    if(root==NULL) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* curr= s.top();
        s.pop();
        cout<< curr->val<<" ";
        if(curr->right!=NULL) s.push(curr->right);
        if(curr->left!=NULL) s.push(curr->left);
    }
}

int main() {
    // Sample tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    preorderTraversal(root);

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
