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

    vector<int> sumLevels(treeNode* root){
        vector<int> result;
        queue<treeNode*>q;
        q.push(root);
        while(!q.empty()){
            int lvl= q.size();
            int sum=0;
            for(int i=0;i<lvl;i++){
                treeNode* curr= q.front();
                q.pop();
                sum= sum+curr->data;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            result.push_back(sum);
        }
        return result;
    }
    
    int main(){
    treeNode* root = new treeNode(2);
    root->left = new treeNode(3);
    root->right = new treeNode(4);
    root->left->left = new treeNode(5);
    root->left->right = new treeNode(6);
    root->right->right = new treeNode(7);
    vector<int>levelProducts= sumLevels(root);
    for(int val: levelProducts) {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}