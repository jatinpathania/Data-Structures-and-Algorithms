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

void postorderTraversal(TreeNode* root) {
    if(root==NULL) return;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root= s1.top();
        s1.pop();
        s2.push(root);
        if(root->left!=NULL){
            s1.push(root->left);
        }
        if(root->right!=NULL){
            s1.push(root->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->val<<" ";
        s2.pop();
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

    postorderTraversal(root);
    cout<<endl;

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
