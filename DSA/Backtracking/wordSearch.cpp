#include <iostream>
#include <vector>
using namespace std;

//Time complexity
// Time Complexity: O(m * n * 4^L)
// Space Complexity: O(L)

class Solution {
public:
    bool find(int i,int j,int m,int n,vector<vector<char>>&board,string& word,int k){
        if(k==word.size()) return true;
        if(i<0 || j<0 || i==m || j==n || board[i][j]!=word[k]) return false;
        char ch= board[i][j];
        board[i][j]='#';
        //moving in directions
        bool op1= find(i+1,j,m,n,board,word,k+1);
        bool op2= find(i,j+1,m,n,board,word,k+1);
        bool op3= find(i-1,j,m,n,board,word,k+1);
        bool op4= find(i,j-1,m,n,board,word,k+1);
        board[i][j]= ch;
        return op1 || op2 || op3|| op4;
    }
    bool exist(vector<vector<char>>& board,string word){
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(board[i][j]==word[0] && find(i,j,m,n,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board ={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout <<(sol.exist(board,word)?"True" : "False")<<endl;
    return 0;
}
