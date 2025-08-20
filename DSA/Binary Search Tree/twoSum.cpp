#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int key){
    if(!root) {
        return new TreeNode(key);
    }
    if(key < root->val) root->left  = insertNode(root->left,  key);
    else                root->right = insertNode(root->right, key);
    return root;
}

class BSTIterator{
    stack<TreeNode*> s;
    bool reverse= true;
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse= isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !s.empty();
    }

    int next(){
        TreeNode* temp= s.top(); s.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
private:
    void pushAll(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            if(reverse== true){
                root= root->right;
            }else{
                root= root->left;
            }
        }
    }
};

void inorder(TreeNode* root, vector<int>& vals){
    if(!root) return;
    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
}

bool findTarget(TreeNode* root, int k) {
    if(root==NULL) return false;
    //next
    BSTIterator l( root,false);
    BSTIterator r( root, true);
    int i= l.next();
    int j= r.next();
    while(i<j){
        if( i+j == k) return false;
        else if(i+j <k) i= l.next();
        else j= r.next();
    }
    return false;
}

int main(){
    /*
                  50
                 /  \
               30    70
              / \    / \
            20  40  60  80
    */

    TreeNode* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    int target = 90;

    if(findTarget(root, target)){
        cout << "Two nodes exist whose sum is " << target << endl;
    }
    else{
        cout << "No two nodes add up to " << target << endl;
    }
    return 0;
}
