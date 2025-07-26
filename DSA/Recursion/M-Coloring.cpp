#include<bits/stdc++.h>
using namespace std;
bool isSafe(int node,int color[], int n,vector<vector<int>>& graph,int col){
    for(int k=0; k<n ; k++){
        if(k!=node && graph[k][node]==1 && color[k]==col) return false;
    }
    return true;
}
bool solve(int node,int color[],int m,int n,vector<vector<int>>& graph){
    if(node==n) return true;

    for(int i=1 ; i<=m ;i++){
        if(isSafe(node,color,n,graph,i)){
            color[node]=i;
            solve(node+1,color,m,n,graph);
            color[node]=0;
        }
    }
    return false;
}

int main(){
    int n,m,e;
    cin>>n>>m>>e;
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]= 1;
        graph[v][u]= 1;
    }
    int color[n] ={0};
    if(solve(0,color,m,n,graph)){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}
