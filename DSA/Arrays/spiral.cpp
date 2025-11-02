#include <bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>>& arr){
    int r= arr.size();
    int c= arr[0].size();
    int minr=0;
    int maxr=r-1;
    int minc=0;
    int maxc=c-1;
    int tne=r*c;
    int count=0;
    vector<int> res;
    while(tne>count){
        // min row
        for(int j=minc; j<=maxc ; j++){
            res.push_back(arr[minr][j]);
            count++;
        }
        minr++;
        if(count>=tne) break;

        //max column
        for(int i=minr ; i<=maxr ;i++){
            res.push_back(arr[i][maxc]);
            count++;
        }
        maxc--;
        if(count>=tne) break;

        //max row
        for(int j=maxc ; j>=minc ;j--){
            res.push_back(arr[maxr][j]);
            count++;
        }
        maxr--;
        if(count>=tne) break;

        //min column
        for(int i=maxr ; i>=minr ;i--){
            res.push_back(arr[i][minc]);
            count++;
        }
        minc++;
        if(count>=tne) break;
    }
    return res;
}


int main() {
    vector<vector<int>> mat{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};        
    vector<int> ans = spiral(mat);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}