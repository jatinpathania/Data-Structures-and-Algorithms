// O(n^2)
#include <iostream>
using namespace std;
int main()
{
    int arr[]={16,17,3,4,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i<n;i++){
        bool flag= true;
        for(int j=i+1 ; j<n ;j++){
            if(arr[i]<=arr[j]){
               flag= false;
               break;
            }
        }
        if(flag==true) cout<<arr[i]<<endl;
    }

return 0;
}


//O(n)  -- optimised

// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[]={16,17,3,4,5,2};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     // trverse from right  
//     int maxRight=arr[n-1];
//     cout<<maxRight<<endl;
//     for(int i= n-2; i>=0 ;i--){
//         if(arr[i]>maxRight){
//             maxRight=arr[i];
//             cout<<maxRight<<endl;
//         }
//     }
// return 0;
// }