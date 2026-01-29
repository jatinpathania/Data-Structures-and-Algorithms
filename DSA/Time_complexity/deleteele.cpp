#include <iostream>
using namespace std;
int main() {
    int arr[] = {5,9,8,7,6,4,12,11,1,13};
    int len= sizeof(arr)/sizeof(arr[0]);
    int n;
    cout<<"Enter idx of element to be deleted : ";
    cin>>n;
    for(int i=n; i <len-1 ; i++){
        arr[i]=arr[i+1];
    }
    arr[len-1]=0;
    for(int i=0 ; i<len ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}