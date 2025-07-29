#include <bits/stdc++.h>
using namespace std;
class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int value){
        data = value;
        left= right = NULL;
    }
};

treeNode* convertArrToBinaryTree(vector<int>arr){
    int n=arr.size();
    treeNode* root= new treeNode(arr[0]);
    queue<treeNode*> q;
    q.push(root);
    for(int i=0;i<n ;i++){
        int LC= i*2+ 1;
        int RC= i*2+ 2;
        treeNode* curr= q.front();
        q.pop();
        if(LC<n){
            treeNode* leftChild= new treeNode(arr[LC]);
            curr->left=leftChild;
            q.push(leftChild);
        }
        if(RC<n){
            treeNode* rightChild= new treeNode(arr[RC]);
            curr->right=rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

treeNode* inOrderTraversal(treeNode* node){
    if(node==NULL) return NULL;
    inOrderTraversal(node->left);
    cout<<node->data<<" ";
    inOrderTraversal(node->right);
    return node;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    treeNode* root= convertArrToBinaryTree(arr);
    root= inOrderTraversal(root);
    cout<<endl;
return 0;
}