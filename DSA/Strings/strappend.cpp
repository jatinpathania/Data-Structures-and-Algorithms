#include <iostream>
using namespace std;
int main()
{
    string str= "world is more powerful";
    string str1="you are not going anywhere ";
    str.append(str1,4,3);
    cout<<str;
return 0;
}

//erase works as 
// str.erase(10,8);

// this deletes 8 elements form 10th index