#include <bits/stdc++.h>
using namespace std;

//Time complexity- O(n)+O(2E)
//Space- O(N)
class Solution {
public:
    void dfs(int v, vector<int> adj[], vector<int>& vis,vector<int>& result){
        vis[v]=1;
        result.push_back(v);

        for(auto it: adj[v]){
            if(!vis[it]){
                dfs(it,adj,vis,result);
            }
        }
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<int> visited(V, 0);
    vector<int> result;
    Solution sol;
    sol.dfs(0, adj, visited, result);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}


// Another form of this code

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// private:
//     void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
//         vis[node] = 1;
//         ls.push_back(node);

//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 dfs(it, adj, vis, ls);
//             }
//         }
//     }

// public:
//     vector<int> dfsOfGraph(int V, vector<int> adj[]){
//         int vis[V] = {0};
//         vector<int> ls;
//         dfs(0, adj, vis, ls);
//         return ls;
//     }
// };

// int main() {
//     int V = 5;
//     vector<int> adj[V];
//     adj[0] = {1, 2};
//     adj[1] = {0, 3};
//     adj[2] = {0, 4};
//     adj[3] = {1};
//     adj[4] = {2};

//     Solution obj;
//     vector<int> result = obj.dfsOfGraph(V, adj);
//     for(int node : result){
//         cout<<node<< " ";
//     }
//     cout << endl;
//     return 0;
// }