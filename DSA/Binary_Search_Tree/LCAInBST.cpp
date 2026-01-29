#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // approach for this quest is.. if both of them lie on left..go left.. if both on right.. go right... and if not on these.. then node itself is LCA

        if(root== NULL) return NULL;
        int curr= root->val;
        if(curr < p->val && curr< q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val && curr > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

void printInOrder(TreeNode* root) {
    if(root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    /*
         Constructing the following BST:
                    6
                   / \
                  2   8
                 / \ / \
                0  4 7 9
                  / \
                 3   5

        Example:  p = 2, q = 8  -> LCA = 6
                   p = 2, q = 4 -> LCA = 2
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    cout << "BST (inorder traversal): ";
    printInOrder(root);
    cout << endl;

    Solution sol;

    TreeNode* p = root->left; 
    TreeNode* q = root->right;
    TreeNode* ans1 = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " = " << ans1->val << endl;

    p = root->left;   
    q = root->left->right;  
    TreeNode* ans2 = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " = " << ans2->val << endl;

    return 0;
}
