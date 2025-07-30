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
    stack<TreeNode*> s;
    TreeNode* curr= root;
    TreeNode* temp;
    while(curr!=NULL|| !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr= curr->left;
        }else{
            temp= s.top()->right;
            if(temp==NULL){
                temp= s.top();
                s.pop();
                cout<<temp->val<<" ";
                while(!s.empty() && temp== s.top()->right){
                    temp= s.top();
                    s.pop();
                    cout<<temp->val<<" ";
                }
            }
            else{
                curr= temp;
            }
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
