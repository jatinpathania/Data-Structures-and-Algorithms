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

    void printNodesAtLevel(treeNode* root,int k){
        if(root==NULL) return;
        queue<treeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int lvlSize= q.size();
            if(level==k){
                for(int i=0;i<lvlSize;i++){
                    treeNode* curr= q.front();
                    q.pop();
                    cout<<curr->data<<" ";
                }
                return;
            }

            for(int i=0;i<lvlSize ;i++){
                treeNode* curr= q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        cout<<"No nodes at the "<<k<<"th level"<<endl;
    }
    
    int main(){
    treeNode* root = new treeNode(2);
    root->left = new treeNode(3);
    root->right = new treeNode(4);
    root->left->left = new treeNode(5);
    root->left->right = new treeNode(6);
    root->right->right = new treeNode(7);
    
    int k;
    cout<<"Enter level number: ";
    cin>>k;
    cout<<"Nodes at level "<<k<<": ";
    printNodesAtLevel(root,k);
    cout<<"\n";
    return 0;
}