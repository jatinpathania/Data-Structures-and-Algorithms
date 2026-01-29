#include <iostream>
using namespace std;
int main()
{
    int arr[]={9,8,7,11,15,12,14,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i<n ;i++){
        bool isLeftValid= true, isRightValid= true;
        for(int j=0 ; j<i;j++){
            if(arr[i]<arr[j]){
                isLeftValid= false;
                break;    // jese hi mila .. sath hi bahr
            }
        }
        for(int j=i ; j<n; j++){
            if(arr[i]>arr[j]){
            isRightValid= false;
            break;
            }
        }

        if(isLeftValid && isRightValid){
            cout<<arr[i]<<" ";
        }
    }
return 0;
}
// O(n^2)


