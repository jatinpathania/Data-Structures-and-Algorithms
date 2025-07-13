#include <iostream>
using namespace std;
int main()
{
    int n=8;
    int arr[n]={8,7,2,1,11,12,9,4};
    int i=0;
    int j=n-1;
    for(i=0 ; i<=n/2; i++){
        swap(arr[i],arr[n-i-1]);
    }
    for(int m=0 ;m<n ;m++){
        cout<<arr[m]<<' ';
    }
return 0;
}

//O(n)