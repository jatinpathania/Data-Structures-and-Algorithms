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

void inorderTraversal(TreeNode* root) {
    if(root==NULL) return;
    stack<TreeNode*> s;
    TreeNode* node= root;
    while(true){
        if(node!=NULL){
            s.push(node);
            node= node->left;
        }else{
            if(s.empty()) break;
            TreeNode* curr= s.top();
            s.pop();
            cout<<curr->val<<" ";
            node= curr->right;
        }
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

    inorderTraversal(root);
    cout<<endl;

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
