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
    int Min(int a,int b){
        if(a>b) return b;
        else return a;
    }
    int Max(int a,int b){
        if(a>b) return a;
        else return b;
    }

    void getMinMaxValues(treeNode* root,vector<int>&minValues,vector<int>&maxValues){
        if(root==NULL) return ;
        queue<treeNode*>q;
        q.push(root);
        while(!q.empty()){
            int lvlSize= q.size();
            int lvlMin= INT_MAX;
            int lvlMax= INT_MIN;
            for(int i=0;i<lvlSize;i++){
                treeNode* curr= q.front();
                q.pop();
                lvlMin= Min(lvlMin,curr->data);
                lvlMax= Max(lvlMax,curr->data);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            minValues.push_back(lvlMin);
            maxValues.push_back(lvlMax);
        }
    }
    
    int main(){
    treeNode* root = new treeNode(2);
    root->left = new treeNode(3);
    root->right = new treeNode(4);
    root->left->left = new treeNode(5);
    root->left->right = new treeNode(6);
    root->right->right = new treeNode(7);
    vector<int> minValues,maxValues;
    getMinMaxValues(root,minValues,maxValues);
    cout<<"Minimum at each level: ";
    for(int val:minValues)cout<<val<<" ";
    cout<< "\n";

    cout<<"Maximum at each level: ";
    for(int val:maxValues)cout<<val<<" ";
    cout<<"\n";
    return 0;
}