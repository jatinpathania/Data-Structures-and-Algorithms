#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>&preorder, int &i, int bound){
    if(i== preorder.size() || preorder[i]> bound) return NULL;
    TreeNode* root= new TreeNode(preorder[i++]);
    root->left= build(preorder,i, root->val);
    root->right= build(preorder, i, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return build(preorder, i, INT_MAX);
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12}; 
    TreeNode* root = bstFromPreorder(preorder);
    inorder(root);
    cout<<endl;
    return 0;
}
