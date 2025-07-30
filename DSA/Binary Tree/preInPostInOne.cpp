#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void allInOneTraversal(TreeNode* root) {
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});
    vector<int> pre,in,post;
    if(root==NULL) return;
    while(!s.empty()){
        auto it= s.top();
        s.pop();

        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->left!=NULL){
                s.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->right!=NULL){
                s.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->val);
        }
    }

    cout << "Preorder: ";
    for (int val : pre) cout << val << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int val : in) cout << val << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int val : post) cout << val << " ";
    cout << endl;
}

int main() {
    // Sample tree:
    //      1
    //     / \
    //    2   5
    //   / \  / \
    //  3   4 6  7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    allInOneTraversal(root);

    // Cleanup
    delete root->right->right;
    delete root->right->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
