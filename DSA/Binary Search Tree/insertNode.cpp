#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr= root;
        while(true){
            if(curr->val <= val){            // this is for checking left side of binary tree
                if(curr->right!=NULL) curr= curr->right;
                else{
                    curr->right= new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL) curr= curr->left;
                else{
                    curr->left= new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    std::cout << "Before Insertion: ";
    s.inorder(root);
    std::cout << std::endl;

    root = s.insertIntoBST(root, 5);

    std::cout << "After Insertion: ";
    s.inorder(root);
    std::cout << std::endl;

    return 0;
}
