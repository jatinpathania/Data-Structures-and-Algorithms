#include<bits/stdc++.h>
using namespace std;

//Less costly
class Graph1{
    private:
    int n;
    vector<vector<int>> adj;

    public:
    Graph1(int n){
        this->n= n;
        adj.resize(n);
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print(){
        for(int i=0; i<n; i++ ){
            cout<<i<< " -> ";
            for(int node: adj[i]){
                cout<< node <<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n=4;
    Graph1 graph(n);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    graph.print();
}

// For storing weighted graphs, store nodes as pairs consisting of edge weight b/w edges instead of just he nodes with indexes.