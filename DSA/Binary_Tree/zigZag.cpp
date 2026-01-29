#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> ZigZagLevelOrder(Node* root){
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<Node*> q;
        bool isLeftToRight= true;
        q.push(root);
        while(!q.empty()){
            int lvlSize= q.size();
            vector<int> row(lvlSize);
            for(int i=0 ;i<lvlSize ;i++){
                Node* curr= q.front();
                q.pop();
                //index selection for simple or reversed pushing
                int index= (isLeftToRight) ? i : (lvlSize-1-i) ;
                row[index]= curr->data;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            isLeftToRight= !isLeftToRight;
            res.push_back(row);
        }
        return res;
    }
};

void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result){
        for (int val : row) {
            cout << val <<" ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);
    printResult(result);
    return 0;
}
          