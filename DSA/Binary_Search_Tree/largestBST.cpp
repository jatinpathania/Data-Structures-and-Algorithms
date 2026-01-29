// brute force- pass to validateBST function and after that count no of nodes using any traversal
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class NodeValue{
    public:
    int maxNode,minNode,maxSize;
    NodeValue(int maxNode, int minNode, int maxSize){
        this->maxNode= maxNode;
        this->minNode= minNode; 
        this->maxSize= maxSize;
    }
};

class Solution {
private:
    NodeValue largestBstHelper(TreeNode* root){
        if(root==NULL) return NodeValue( INT_MAX, INT_MIN, 0 );

        auto leftNode= largestBstHelper(root->left);
        auto rightNode= largestBstHelper(root->right);

        //current node is greater than largest from left and smaller than smallest from right
        if(leftNode.maxNode < root->val && root->val < rightNode.minNode){
            // it is a BST
            return NodeValue( min(root->val , leftNode.minNode), max( root->val, rightNode.maxNode ), 1+ leftNode.maxSize+ rightNode.maxSize );
        }
        // if not a bst.. then give largest value for future comparison
        return NodeValue( INT_MIN, INT_MAX, max(leftNode.maxSize , rightNode. maxSize) );
    }

public:
    int largestBST(TreeNode* root) {
        return largestBstHelper(root).maxSize;
    }
};

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);
    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);

    Solution s;
    cout << s.largestBST(root) << endl;
    return 0;
}
