#include <bits/stdc++.h>
using namespace std;
int main()
{
    //unordered set
    //methods
    //1. insert()
    //2. size()
    //3. empty()
    //4. erase()
    //5. clear()
    //6. begin()
    //7. end()
    //8. find()

    //initilization
    unordered_set<char> uset;
    string str= "abcdefabcdef";
    //converting string to unordered set
    for(int i=0;i<str.length();i++){
        uset.insert(str[i]);
    }

    //printing/ traversing through for i loop (old fashioned)
    // for(unordered_set<char>:: iterator itr= uset.begin();itr!=uset.end();i++){
    //     cout<<*itr<<" ";
    // }


    //printing/ traversing through for each loop(new method)
    for(char ch: uset){
        cout<<ch<<" ";
    }
return 0;
}