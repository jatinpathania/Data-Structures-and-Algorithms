#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parent_map[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_map[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int minTimeToBurn(TreeNode* root, TreeNode* target) {
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* target = root->left;  // Node 2
    Solution s;
    cout << "Minimum time to burn the tree: " << s.minTimeToBurn(root, target) << endl;
    return 0;
}
