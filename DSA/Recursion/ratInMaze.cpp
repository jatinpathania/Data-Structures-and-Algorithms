// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;
// class Solution{
// public:
//     void solve(int i,int j,vector<vector<int>>& maze,int n,vector<vector<int>>&vis,string move,vector<string>&ans){
//         if(i==n-1 && j==n-1){
//             ans.push_back(move);
//             return;
//         }
//         vis[i][j]=1;
//         //downward
//         if(i+1 <n && !vis[i+1][j] && maze[i+1][j]==1){
//             solve(i+1,j,maze,n,vis,move+"D",ans);
//         }
//         //left
//         if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]==1){
//             solve(i,j-1,maze,n,vis,move+"L",ans);
//         }
//         //right
//         if(j+1 <n && !vis[i][j+1] && maze[i][j+1]==1){
//             solve(i,j+1,maze,n,vis,move+"R",ans);
//         }
//         //upward
//         if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]==1){
//             solve(i-1,j,maze,n,vis,move+"U",ans);
//         }
//         vis[i][j]=0;
//     }
//     vector<string> findPath(vector<vector<int>>& maze,int n){
//         vector<string> ans;
//         vector<vector<int>> vis(n,vector<int>(n,0));
//         if(maze[0][0]==1) solve(0,0,maze,n,vis,"",ans); 
//         return ans;
//     }
// };

// int main(){
//     vector<vector<int>> maze ={
//         {1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}
//     };

//     Solution s;
//     vector<string>paths = s.findPath(maze, 4);
//     for (string path :paths) {
//         cout <<path<<endl;
//     }

//     return 0;
// }


// shorter code

#include <bits/stdc++.h>
using namespace std;
class Solution{
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {+1,0,0,-1};
      int dj[] = {0,-1,1,0};
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
};

int main() {
  int n = 4;

 vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
   
  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}