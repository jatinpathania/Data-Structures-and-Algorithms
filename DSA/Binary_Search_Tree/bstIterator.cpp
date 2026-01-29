#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* node) {
        while(node!=NULL){
            st.push(node);
            node= node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp= st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
};

TreeNode* insertNode(TreeNode* root, int key){
    if(!root) {
        return new TreeNode(key);
    }
    if(key < root->val) {
        root->left  = insertNode(root->left, key);
    } else if(key > root->val) {
        root->right = insertNode(root->right, key);
    }
    return root;
}
int main(){

    /*
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

    BSTIterator iterator(root);

    cout << "Inorder traversal using BSTIterator: ";
    while(iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;
    return 0;
}
