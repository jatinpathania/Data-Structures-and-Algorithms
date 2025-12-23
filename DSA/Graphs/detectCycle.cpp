//Using BFS
// Time complexity- O(N)+O(2E)
//Space complexity- O(N)

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//     private:
//     bool detect(int src, vector<int>adj[], int vis[]){
//         vis[src]=1;
//         queue<pair<int,int>> q;
//         q.push({ src,-1 });
//         while(!q.empty()){
//             int node= q.front().first;
//             int parent= q.front().second;
//             q.pop();
//             for(auto adjacentNode: adj[node] ){
//                 if(!vis[adjacentNode]){
//                     vis[adjacentNode]=1;
//                     q.push({adjacentNode, node});
//                 }
//                 else if(parent!= adjacentNode){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     public:
//     bool isCycle(int V, vector<int> adj[]){
//         // for loop for checking if graph is component or not
//         int vis[V]= {0};
//         for(int i=0;i <V ;i++){
//             if(!vis[i]){
//                 if(detect(i, adj, vis)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// int main() {
    
//     // V = 4, E = 2
//     vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
//     Solution obj;
//     bool ans = obj.isCycle(4, adj);
//     if (ans)
//         cout << "1\n";
//     else
//         cout << "0\n";
//     return 0;
// }


//Using DFS
// Time complexity- O(N)+O(2E)+O(N)
//Space complexity- O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node]= 1;
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, node, vis, adj)== true) return true;
            }
            else if(parent!= adjacentNode){
                return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V]={0};
        for(int i=0; i<V ;i++){
            if(!vis[i]){
                if(dfs(i,-1, vis, adj)== true) return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    // Add edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1); 

    Solution sol;
    if (sol.isCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle found\n";
    return 0;
}