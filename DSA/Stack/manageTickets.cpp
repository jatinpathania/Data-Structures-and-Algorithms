#include <iostream>
#include <vector>
using namespace std;

vector<int> manageQueue(int n, int m, vector<int>& arr) {
    vector<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && m > 0 && st.back() < arr[i]) {
            st.pop_back();
            m--;
        }
        st.push_back(arr[i]);
    }
    return st;
}

int main(){
    vector<int> arr = {3, 2, 6, 1, 9};
    int n = arr.size();
    int m = 2;
    vector<int> result = manageQueue(n, m, arr);
    cout << "Result: ";
    for(int val : result) cout << val << " ";
    cout << endl;
    
    return 0;
}