#include<bits/stdc++.h>
using namespace std;
//More costly
class Graph1{
    private:
    int n;
    vector<vector<int>> adjacencyMatrix;

    public:
    Graph1(int n){
        this->n= n;
        adjacencyMatrix= vector<vector<int>>(n, vector<int>(n,0));
    }

    void addEdge(int u,int v){
        adjacencyMatrix[u][v]= 1;
        adjacencyMatrix[v][u]= 1;
    }

    void print(){
        for(int i=0; i<n ;i++){
            for(int j=0; j< n; j++){
                cout<< adjacencyMatrix[i][j]<<" ";
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

//For weighted graphs, instead of putting 1, we put actual weight in matrix for the edges