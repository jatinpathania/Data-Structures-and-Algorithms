#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string str= "abcpqr123*!#";
    string str1= "xabxqxpqxci2x xlx";
    string str2= "abapqcqpbalbcmp";

    // printing chars
    // for(int i=0 ; i<str.length();i++){
    //     cout<<str[i]<<" ";
    // }

    //return index of '!'
    // for(int i=0 ; i<str.length() ;i++){
    //     if(str[i]=='!'){
    //         cout<<i;
    //     }
    // }

    // count of all occurances of ch in str
    // int count=0;
    // for(int i=0 ; i<str1.length() ; i++){
    //     if(str1[i]=='x'){
    //         count++;
    //     }
    // }
    // cout<<count;


    //remove occurances of 'x
    // str1.erase(remove(str1.begin(), str1.end(), 'x'), str1.end());
    // cout<<str1;


    //remove all duplicates
    for(int i =0 ; i<str2.length() ; i++){
        for(int j=i+1 ; j<str2.length() ; j++){
            if(str2[i]==str2[j]){
                str2.erase(j,1);
                j--;
            }
        }
    }
    cout<<str2;
return 0;
}