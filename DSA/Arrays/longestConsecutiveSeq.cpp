#include <bits/stdc++.h>
using namespace std;

//optimal solution
int longestSuccessiveElements(vector<int>&a){
    int n= a.size();
    if(a.size() ==0) return 0;
    int longest= 1;
    unordered_set<int> s;
    for(int i=0 ;i <n ;i++){
        s.insert(a[i]);
    }

    for(auto ele : s){
        if(s.find(ele-1) == s.end()){
            int cnt=1;
            int x= ele;
            while(s.find(x+1) != s.end()){
                x= x+1;
                cnt++;
            }
            longest= max(longest, cnt);
        }
    }
    return longest;
}

// better solution
// int longestSuccessiveElements(vector<int>&a){
//     if(a.size() ==0) return 0;
//     sort(a.begin(), a.end());
//     int cnt=0;
//     int lastSmaller= INT_MIN;
//     int longest= 1;
//     for(int i=0; i< a.size() ;i++){
//         if( a[i]-1 == lastSmaller ){
//             cnt++;
//             lastSmaller= a[i];
//         }
//         else if(a[i]!= lastSmaller){
//             cnt= 1;
//             lastSmaller= a[i];
//         }
//         longest= max(longest, cnt);
//     }
//     return longest;
// }

int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}