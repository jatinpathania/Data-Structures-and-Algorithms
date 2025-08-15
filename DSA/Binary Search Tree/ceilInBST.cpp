#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    int findCeil(TreeNode* root, int key){
        int ceil= -1;
        while(root!=NULL){
            if(root->val  == key){
                ceil= root->val;
                return ceil;
            }

            if(key >= root->val){
                root= root->right;
            }
            else{
                ceil = root->val;          // This becomes a candidate for ceil
                root= root->left;
            }
        }
        return ceil;
    }
};

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    int target = 8;
    int ciel = solution.findCeil(root, target);
    
    if(ciel != -1){
        cout << "Ceiling of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No ceiling found!";
    }
    return 0;
}
           