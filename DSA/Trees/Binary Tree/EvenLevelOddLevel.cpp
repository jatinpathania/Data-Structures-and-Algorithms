#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val){
        data=val;
        left=right=NULL;
    }
};

    void getEvenOddLevels(treeNode* root,vector<int>&evenLevelNodes,vector<int>&oddLevelNodes){
        if(root==NULL) return;
        queue<treeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int lvlSize= q.size();
            for(int i=0;i<lvlSize ;i++){
                treeNode* curr= q.front();
                q.pop();
                if(level%2==0){
                    evenLevelNodes.push_back(curr->data);
                }else{
                    oddLevelNodes.push_back(curr->data);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
    }
    
    int main(){
    treeNode* root = new treeNode(2);
    root->left = new treeNode(3);
    root->right = new treeNode(4);
    root->left->left = new treeNode(5);
    root->left->right = new treeNode(6);
    root->right->right = new treeNode(7);
    vector<int> evenLevelNodes;
    vector<int> oddLevelNodes;
    getEvenOddLevels(root,evenLevelNodes,oddLevelNodes);
    cout<<"Even Level Nodes: ";
    for(int val:evenLevelNodes)cout<<val<<" ";
    cout<<"\n";

    cout<<"Odd Level Nodes: ";
    for(int val:oddLevelNodes)cout<<val<<" ";
    cout<<"\n";
    cout<<endl;
    return 0;
}