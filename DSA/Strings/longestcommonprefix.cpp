// #include <iostream>
// using namespace std;
// string longestCommonPrefix(string strs[], int n) {
//     string ans="";
//     for(int i=0 ; i<strs[0].length() ;i++){
//         for(int j=0 ; j <n-1 ;j++){
//             if(strs[j][i]!=strs[j+1][i]) return ans;
//         }
//         ans= ans+strs[0][i];
//     }
//     return ans;
// }
// int main()
// {
//     string str[]= {"CodeQuotient","Code","Coding"};
//     int n= sizeof(str)/sizeof(str[0]);
//     string res= longestCommonPrefix(str,n);
//     cout<<res<<endl;
// return 0;
// }



// Optimised code  O(nlogn)
//Comparing only the first and last element after sorting


#include <iostream>
#include <algorithm>
using namespace std;
string longestCommonPrefix(string strs[], int n) {
    if(n==0) return "";
    sort(strs,strs+n);
    string first= strs[0];
    string last= strs[n-1];
    string prefix="";
    int i=0;
    while(i<first.length() && i<last.length()){
        if(first[i]==last[i]){
            prefix= prefix+first[i];
        }
        else{
            break;
        }
        i++;
    }
    return prefix;
}
int main()
{
    string str[]= {"CodeQuotient","Code","Coding"};
    int n= sizeof(str)/sizeof(str[0]);
    string res= longestCommonPrefix(str,n);
    cout<<res<<endl;
return 0;
}