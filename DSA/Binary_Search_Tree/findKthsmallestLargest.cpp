//The inorder of any BST is always sorted as left eles are smaller and right ones are larger
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
private:
    void reverseInorder(TreeNode* root, int& count, int k, int& kthLargest){
        if(root==NULL ||count>= k) return ;
        reverseInorder( root->right, count, k , kthLargest);
        count++;
        if(count== k){
            kthLargest= root->val;
            return;
        }
        reverseInorder(root->left,count, k , kthLargest);
    }

    void inorder(TreeNode* root, int& count, int k, int& kthSmallest){
        if(root==NULL || count>= k) return;

        inorder(root->left, count, k, kthSmallest);
        count++;
        if(count== k){
            kthSmallest= root->val;
            return;
        }
        inorder(root->right, count, k, kthSmallest);
    }

public:
    pair<int, int> findKth(TreeNode* root, int k) {
        int kthSmallest= INT_MAX;
        int kthLargest= INT_MIN;
        
        int count= 0;
        inorder(root, count, k, kthSmallest);
        count=0;
        reverseInorder(root,count, k, kthLargest);
        return make_pair(kthSmallest,kthLargest);
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
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = solution.findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}
                                
             