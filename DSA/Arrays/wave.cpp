#include <bits/stdc++.h>
using namespace std;

vector<int> wavePattern(vector<vector<int>>& arr){
    int r= arr.size();
    int c= arr[0].size();
    vector<int> res;
    for(int i=0 ; i<r ;i++){
        if(i%2==0){
            for(int j=0 ; j<c ;j++){
                res.push_back(arr[i][j]);
            }
        }
        else{
            for(int j=c-1 ; j>=0 ;j--){
                res.push_back(arr[i][j]);
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> arr={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};        
    vector<int> ans = wavePattern(arr);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
return 0;
}