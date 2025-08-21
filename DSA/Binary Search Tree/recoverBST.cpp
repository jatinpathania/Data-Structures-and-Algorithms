#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        if(prev!=NULL && root->val <prev->val){
            //for first violation
            if(first == NULL){
                first= prev;
                middle= root;
            }
            else{
                last = root;        //second violation
            }
        }
        prev= root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first= prev= middle= NULL;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};

TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /* Example tree:
            3
           / \
          1   4
             /
            2

       The correct BST should be:
            2
           / \
          1   4
             /
            3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before fixing (inorder): ";
    printInorder(root);
    cout << endl;
    Solution().recoverTree(root);
    cout << "After fixing (inorder): ";
    printInorder(root);
    cout << endl;
    return 0;
}
