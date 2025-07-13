#include <iostream>
using namespace std;
int main()
{
    int r,c;
    cout<<"Enter no of rows and columns: ";
    cin>>r>>c;
    int arr[r][c];
    for(int i=0 ; i<r; i++){
        for(int j=0 ; j<c ;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0 ; i<r ;i++){
        if(i%2==0){
            for(int j=0 ; j<c ;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int j=c-1 ; j>=0 ;j--){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}