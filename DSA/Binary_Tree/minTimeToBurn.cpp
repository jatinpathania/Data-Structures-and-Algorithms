#include <iostream>
#include<unordered_map>
#include <queue>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findMaxTime(unordered_map<TreeNode*,TreeNode*> &parent_map , TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, int> isVisited;
        isVisited[target]= 1;
        int maxi=0;
        while(!q.empty()){
            int size= q.size();
            int fl=0;
            for(int i=0; i<size ;i++){
                auto node= q.front();
                q.pop();
                if(node->left!=NULL && !isVisited[node->left]){
                    fl=1;
                    isVisited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right!=NULL && !isVisited[node->right]){
                    fl=1;
                    isVisited[node->right]=1;
                    q.push(node->right);
                }
                if(parent_map[node] && !isVisited[parent_map[node]]){
                    fl=1;
                    isVisited[parent_map[node]]=1;
                    q.push(parent_map[node]);
                }
            }
            if(fl!=0) maxi++;
        }
        return maxi;
    }
    
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr->left){
                parent_map[curr->left]= curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_map[curr->right]= curr;
                q.push(curr->right);
            }
        }
    }

    int minTimeToBurn(TreeNode* root, TreeNode* target) {
        unordered_map<TreeNode*,TreeNode*> parent_map;
        markParents(root, parent_map);
        int maxi= findMaxTime( parent_map, target);
        return maxi;
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
