#include <iostream>
using namespace std;
string recu(string str){
    bool  isadjDup=false;
    string result;
    if(str.empty()){
        return str;
    }
    for(int i=0 ;i<str.length() ;i++){
        if(str[i]==str[i+1]){
            isadjDup=true;
            i++;
        }
        else{
            result=result +str[i];
        }
    }
    if(isadjDup == true){
        return recu(result);
    }
    return result;
}
int main()
{
    string str="xyzppzymmsxpppp";
    string str1="xyzsszyx";
    string str2= "abbccddeefggh";
    string ans= recu(str2);
    cout<<ans;
return 0;
}