#include<bits/stdc++.h>
using namespace std;

//Time complexity- O(2^N)
int solver(vector<int>& arr, int i, int sum, int target){
    if(sum== target) return 1;
    if(i== arr.size() || sum> target) return 0;
    if(solver(arr, i+1, sum+ arr[i], target)) return 1;
    if(solver(arr, i+1, sum, target)) return 1;
    return 0;
}

int subsetSumExists(vector<int>& arr, int target){
    return solver(arr, 0, 0, target);
}

int main(){
    vector<int> arr= {1, 4, 5, 10, 16};
    int sum1= 9;
    int result1= subsetSumExists(arr, sum1);
    cout<< "Array: { ";
    for(int i= 0; i< arr.size(); i++){
        cout<< arr[i];
        if(i< arr.size()- 1) cout<< ", ";
    }
    cout<< " }" << endl;

    cout<< "Sum = " << sum1 << " => " << result1 << endl;

    int sum2= 7;
    int result2= subsetSumExists(arr, sum2);
    cout<< "Sum = " << sum2 << " => " << result2 << endl;

    return 0;
}