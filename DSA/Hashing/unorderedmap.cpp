#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,string> umap;
    umap.insert({1,"ABC"});
    umap.insert({2,"DEF"});
    umap.insert({3,"GHI"}); 
    umap.insert({2,"JKF"});

    //using for i loop
    // for(unordered_map<int,string>:: iterator itr=umap.begin(); itr!=umap.end();itr++){
    //     cout<<itr->first<<" "<<itr->second<<endl;
    // }

    for(int i=0;i<umap.size() ;i++){
        cout<<umap[i]<<" ";
    }
return 0;
}