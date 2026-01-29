//This is the optimised code.. for brute force . we can use any traversal .. like inorder or any other

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int leftH= findHeightLeft(root);
        int rightH= findHeightRight(root);
        
        if(leftH== rightH) return (1<<leftH) -1;

        return 1+ countNodes(root->left)+ countNodes(root->right);
    }
    
    int findHeightLeft(TreeNode* node) {
        int heit= 0;
        while(node){
            heit++;
            node=node->left;
        }
        return heit;
    }
    
    int findHeightRight(TreeNode* node) {
        int heit= 0;
        while(node){
            heit++;
            node=node->right;
        }
        return heit;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    int totalNodes = sol.countNodes(root);

    cout << "Total number of nodes in the Complete Binary Tree: "<< totalNodes << endl;
    return 0;
}      