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

class BinaryTree{
    public:
    treeNode* root;
    // Build tree from array
    void buildTreeFromArray(vector<int> arr,int n){
        root=new treeNode(arr[0]);
        queue<treeNode*> q;
        q.push(root);
        for(int i=0;i<n;i++){
            int LCi= i*2+1;
            int RCi= i*2+2;
            treeNode* curr= q.front();
            q.pop();    
            if(LCi<n){
                treeNode* leftChild= new treeNode(arr[LCi]);
                curr->left= leftChild;
                q.push(leftChild);
            }
            if(RCi<n){
                treeNode* rightChild= new treeNode(arr[RCi]);
                curr->right= rightChild;
                q.push(rightChild);
            }
        }
    }

    // level order traversal
    void levelOrderTraversal(){
        if(root==NULL) return;
        queue<treeNode*> q;
        q.push(root);
        while(!q.empty()){
            treeNode* curr= q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        cout<<endl;
    }


    void levelWiseTraversal(){
        if(root==NULL) return;
        queue<treeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvlSize=q.size();
            for(int i=0;i<lvlSize;i++){
                treeNode* curr= q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            cout<<endl;
        }
    }
};

int main()
{
    BinaryTree myTree;
    vector<int> arr={1,2,3,4,5,6,7};
    int n= arr.size();
    myTree.buildTreeFromArray(arr,n);
    myTree.levelOrderTraversal();
    myTree.levelWiseTraversal();
return 0;
}