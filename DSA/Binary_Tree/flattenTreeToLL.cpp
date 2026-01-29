#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // O(N) both time and space complexity
    // TreeNode* prev= NULL;
    // void flatten(TreeNode* root) {
    //     if(root==NULL) return;
    //     flatten(root->right);
    //     flatten(root->left);
    //     root->right= prev;
    //     root->left= NULL;
    //     prev= root;
    // }

    //O(N) both time and space complexity
    // void flatten(TreeNode* root) {
    //     if(root==NULL) return;
    //     stack<TreeNode*> s;
    //     s.push(root);
    //     while(!s.empty()){
    //         TreeNode* curr= s.top();
    //         s.pop();
    //         if(curr->right) s.push(curr->right);
    //         if(curr->left) s.push(curr->left);
    //         if(!s.empty()){
    //             curr->right= s.top();
    //             curr->left= NULL;
    //         }
    //     }
    // }


    // optimised sol O(N) and O(1)

    void flatten(TreeNode* root) {
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* prev= curr->left;
                while(prev->right!=NULL){
                    prev= prev->right;
                }
                prev->right= curr->right;
                curr->right= curr->left;
                curr->left= NULL;
            }
            curr= curr->right;
        }
    }
};

void printPreorder(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printFlattenTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    sol.flatten(root);
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    return 0;
}
  