#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    vector<int> bottomView(Node* root){
        vector<int> res;
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            Node* node= it.first;
            int line= it.second;
            mpp[line]= node->data;
            if(node->left){
                q.push({node->left, line-1});
            }
            if(node->right){
                q.push({node->right, line+ 1});
            }
        }
        for(auto p: mpp){
            res.push_back(p.second);
        }
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vector<int> bottomView =solution.bottomView(root);
    cout << "Bottom View Traversal: "<< endl;
    for(auto node: bottomView){
        cout << node << " ";
    }
    return 0;
}
            