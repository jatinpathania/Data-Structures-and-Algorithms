#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    int diameterOfBinaryTree(Node* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    int height(Node* node, int& diameter){
        if(node==NULL) return 0;
        int leftH= height(node->left, diameter);
        int rightH= height(node->right, diameter);
        diameter= max(diameter, leftH+ rightH);
        return 1 + max(leftH , rightH); 
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "The diameter of the binary tree is: " << diameter << endl;
    return 0;
}