#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int n= arr.size();
    int mini =arr[0];
    int profit=0;
    for(int i=1 ;i <n; i++){
        int cost = arr[i]- mini; 
        profit= max(profit, cost);
        mini= min(mini, arr[i]);
    }
    return profit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
