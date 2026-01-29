#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int key){
    if(root == nullptr) {
        return new TreeNode(key);
    }
    if(key < root->val){
        root->left = insertNode(root->left, key);
    } else if(key > root->val) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p){
    if(root==NULL ) return NULL;
    TreeNode* predecessor= NULL;
    while(root!=NULL){
        if(p->val >= root->val){
            predecessor= root;
            root= root->right;
        }
        else{
            root= root->left;
        }
    }
    return predecessor;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    if(root==NULL) return NULL;
    TreeNode* successor= NULL;
    while(root!=NULL){
        if(p->val >= root->val){
            root= root->right;
        }
        else{
            successor= root;
            root= root->left;
        }
    }
    return successor;
}

int main(){
    /*
           BST used in this example:

                  50
                 /  \
               30    70
              / \    / \
            20  40  60  80

       Inorder Traversal -> 20, 30, 40, 50, 60, 70, 80
    */

    TreeNode* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    TreeNode* nodeToFind = new TreeNode(60);

    // Predecessor
    TreeNode* pred = inorderPredecessor(root, nodeToFind);
    if(pred != nullptr){
        cout << "Inorder predecessor of " << nodeToFind->val << " is " << pred->val << endl;
    } else {
        cout << "Inorder predecessor does not exist for " << nodeToFind->val << endl;
    }

    // Successor
    TreeNode* succ = inorderSuccessor(root, nodeToFind);
    if(succ != nullptr){
        cout << "Inorder successor of " << nodeToFind->val << " is " << succ->val << endl;
    } else {
        cout << "Inorder successor does not exist for " << nodeToFind->val << endl;
    }
    return 0;
}
