#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr= root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr= curr->left;
            else curr= curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr= root->right;
        vector<int> rev;
        while(curr){
            if(!isLeaf(curr)) rev.push_back(curr->data);
            if(curr->left) curr= curr->left;
            else curr= curr->right;
        }
        for(int i= rev.size()-1 ; i>=0 ;i--){
            res.push_back(rev[i]);
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left,res);
        addLeaves(root->right,res);
    }

    vector<int> printBoundary(Node* root) {
        vector<int> res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        return res;
    }
};

void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
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
    vector<int> result = solution.printBoundary(root);
    cout << "Boundary Traversal: ";
    printResult(result);
    return 0;
}