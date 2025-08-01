#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    bool isBalanced(Node* root) {
        return dfsHeight(root)!=-1;
    }

    int dfsHeight(Node* root){
        if(root==NULL) return 0;
        int leftH= dfsHeight(root->left);
        if(leftH == -1) return -1;
        int rightH= dfsHeight(root->right);
        if(rightH== -1) return -1;

        if(abs(leftH - rightH) >1) return -1;
        return 1+ max(leftH,rightH);
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

    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}