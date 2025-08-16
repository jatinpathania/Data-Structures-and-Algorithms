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

    int floorInBST(TreeNode* root, int key){
        int floor= -1;
        while(root!=NULL){
            if(root->val  == key){
                floor= root->val;
                return floor;
            }

            if(key > root->val){
                floor= root->val;
                root= root->right;
            }
            else{
                root= root->left;
            }
        }
        return floor;
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
    int ciel = solution.floorInBST(root, target);
    
    if(ciel != -1){
        cout << "Floor of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No floor found!";
    }
    return 0;
}
          