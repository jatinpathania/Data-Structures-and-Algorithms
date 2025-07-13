#include <iostream>
//#include <bits/stdc++.h>      it includes all standard libraries
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    // Map
    // Map<key,value>
    // key is the no
    // value is the frequency that no has occured in the Map  

    // Map stores all the values in sorted order.
    // Storing or fetching in map takes log(n) in all cases whether its best or worst


    // We have to always use unordered map first because it has time complexity of O(1) while ordered map has O(n) ...but in some cases when unordered 
    // map gives time limit exceeded ,,only then we have to use ordered map but that case of unordered map is very rare case.. and that case gives
    // time complexity same as ordered map i.e O(n) ...this case happens due to internal collisions 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //precompute
    map<int, int> mpp;            // declaration of ordered map
    unordered_map<int,int> mpp1;      //declaration of unordered map
    for(int i=0;i<n ;i++){
        mpp[arr[i]]++;
    }

    //proof map stored integers in sorted order
    // for(auto i : mpp){
    //     cout<<i.first<<"-->"<<i.second<<endl;
    // }
    
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<mpp[num]<<endl;
    }
return 0;
}