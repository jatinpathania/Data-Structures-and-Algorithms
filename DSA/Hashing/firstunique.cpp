#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<char,int> fmap;
    string str="abzabqprxzp";
    for(char ch: str){
        fmap[ch]++;
    }
    for(int i=0;i<str.length();i++){
        if(fmap[str[i]]==1) cout<<str[i];
    }

return 0;
}

//alpha= no fo elements/size of HT