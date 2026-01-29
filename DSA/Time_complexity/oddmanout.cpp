#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,3,2,3,1,7,5,5,7,2,1,2,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    int oddmanout=0;
    for(int i=0 ; i<n ;i++){
        oddmanout^=arr[i];    // nyi value find hoti e,, but old one gets canceled also with XOR
        // its like X^Y^Y=X .. means only not canceled one shall remain and that's the answer
    }
    cout<<oddmanout<<endl;
return 0;
}