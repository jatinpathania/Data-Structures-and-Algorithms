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

class Solution {
public:
    vector<vector<int>> findVertical(Node* root){
        map<int, map<int,multiset<int>>> nodes;
        queue<pair<Node*, pair<int,int>>>  todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p= todo.front();
            todo.pop();
            Node* node= p.first;
            int x= p.second.first, y= p.second.second;
            nodes[x][y].insert(node->data);
            if(node->left){
                todo.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                todo.push({node->right,{x +1, y+1}});
            }
        }

        vector<vector<int>> res;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};

void printResult(const vector<vector<int>>& result) {
    for(auto level: result){
        for(auto node: level){
            cout << node<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}

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
    vector<vector<int>> verticalTraversal =solution.findVertical(root);
    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);

    return 0;
}
                        