#include <iostream>
using namespace std;
int main()
{
    string str="Code Quotient";
    int len= str.length();
    int i = 0;
    int j= len-1;
    while(i<j){
        int temp= str[i];
        str[i]= str[j];
        str[j]= temp;
        i++;
        j--;
    }
    cout<<str<<endl;
return 0;
}