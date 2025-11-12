#include <bits/stdc++.h>
using namespace std;

//optimal solution
vector<int> majorityElement(vector<int> v){
    int n= v.size();
    int cnt1=0, cnt2=0;
    int ele1= INT_MIN;
    int ele2= INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(cnt1==0 && v[i]!=ele2){
            cnt1++;
            ele1= v[i];
        }
        else if(cnt2==0 && v[i]!=ele1){
            cnt2++;
            ele2= v[i];
        }
        else if(v[i]== ele1) cnt1++;
        else if(v[i]== ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0, cnt2=0;
    for(int i=0; i<v.size(); i++){
        if(ele1== v[i]) cnt1++;
        if(ele2== v[i]) cnt2++;
    }
    int mini= (int)(n/3)+1;
    if(cnt1>= mini ) ls.push_back(ele1);
    if(cnt2>= mini ) ls.push_back(ele2);
    sort(ls.begin(),  ls.end());
    return ls;
}

//better sol   O(2 log 2)
// vector<int> majorityElement(vector<int> v) {
//     int n= v.size();
//     vector<int> ls;
//     unordered_map<int,int> mpp;
//     int mini= (int)(n/3)+1;
//     for(int i=0; i<n; i++){
//         mpp[v[i]]++;
//         if(mpp[v[i]] == mini){
//             ls.push_back(v[i]);
//         }
//         if(ls.size() == 2) break;           // at max, it can be 2
//     }
//     sort(ls.begin(), v.end());
//     return ls;
// }

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}