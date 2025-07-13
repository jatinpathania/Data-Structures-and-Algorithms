#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    //pre compute
    int hash[26]={0};
    for(int i=0; i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int q;
    cout<<"Enter the no of queries: ";
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter the query: ";
        cin>>ch;
        cout<<hash[ch-'a']<<endl;
    }
return 0;
}   