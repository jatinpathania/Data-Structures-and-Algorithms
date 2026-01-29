#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* findLastChild(TreeNode* root){
        if(root ->right ==NULL) return root;
        return findLastChild(root->right);
    }

    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;

        TreeNode* rightChild= root->right;
        TreeNode* lastChild= findLastChild(root->left);

        //simply connecting left directly with right
        lastChild->right= rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val ==key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root!= NULL){
            if(root->val > key){
                if(root->left!= NULL && root->left->val== key){
                    root->left= helper(root->left);
                    break;
                }
                else{
                    root= root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val== key){
                    root->right= helper(root->right);
                    break;
                }
                else{
                    root= root->right;
                }
            }
        }
        return dummy;
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }
};

int main() {
    Solution s;

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    std::cout << "Before Deletion: ";
    s.inorder(root);
    std::cout << std::endl;

    root = s.deleteNode(root, 3);

    std::cout << "After Deletion: ";
    s.inorder(root);
    std::cout << std::endl;

    return 0;
}
