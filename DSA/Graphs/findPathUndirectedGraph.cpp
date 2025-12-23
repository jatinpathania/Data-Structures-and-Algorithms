#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int dest, vector<vector<int>> &adj, vector<bool> &visited) {
    if(src == dest) return true;
    visited[src]= true;
    for(auto it: adj[src]){
        if(!visited[it]){
            if(dfs(it, dest, adj, visited)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Directed edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[2].push_back(4);

    int source = 0;
    int destination = 4;
    vector<bool> visited(V, false);
    if (dfs(source, destination, adj, visited))
        cout << "Path exists\n";
    else
        cout << "Path does not exist\n";

    return 0;
}
