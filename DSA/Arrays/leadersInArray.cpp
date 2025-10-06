#include <bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n){
    int leader= INT_MIN;
    vector<int> res;
    for(int i= n-1 ;i>=0 ;i--){
        if(arr[i]> leader){
            res.push_back(arr[i]);
        }
        leader= max(leader, arr[i]);
    }
    //if order
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};
    vector<int> ans = printLeaders(arr, n);
    for (int i = 0; i< ans.size() ;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}