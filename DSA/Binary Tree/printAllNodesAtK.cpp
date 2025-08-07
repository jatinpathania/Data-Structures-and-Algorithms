#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_map,TreeNode* target){
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_map;
        markParents(root,parent_map,target);
        
        queue <TreeNode*> q;
        unordered_map<TreeNode*, bool> isVisited;
        int currLevel = 0;
        q.push(target);
        isVisited[target]= true;
        while(!q.empty()){
            int size= q.size();
            //condition to reach the distance and break;
            if(currLevel == k) break;
            currLevel++;
            for(int i=0;i<size ;i++){
                TreeNode* curr= q.front();
                q.pop();
                if(curr->left!=NULL && !isVisited[curr->left] ){
                    q.push(curr->left);
                    isVisited[curr->left]= true;
                }
                if(curr->right!=NULL && !isVisited[curr->right]){
                    q.push(curr->right);
                    isVisited[curr->right]= true;
                }
                if(parent_map[curr]!=NULL && !isVisited[parent_map[curr]]){
                    q.push(parent_map[curr]);
                    isVisited[parent_map[curr]]= true;
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            res.push_back(curr->data);
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* target = root->left;
    int k = 2;

    Solution s;
    vector<int> result = s.distanceK(root, target, k);
    for (int val : result) cout << val << " ";
    cout << endl;
    return 0;
}
