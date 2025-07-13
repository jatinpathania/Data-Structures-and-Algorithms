#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0 ; i<r; i++){
        for(int j=0 ; j<c ;j++){
            cin>>arr[i][j];
        }
    }
    int minr=0;
    int maxr=r-1;
    int minc=0;
    int maxc=c-1;
    int tne=r*c;
    int count=0;
    while(tne>count){
        // min row
        for(int j=minc; j<=maxc ; j++){
            cout<<arr[minr][j]<<" ";
            count++;
        }
        minr++;
        if(count>=tne) break;

        //max column
        for(int i=minr ; i<=maxr ;i++){
            cout<<arr[i][maxc]<<" ";
            count++;
        }
        maxc--;
        if(count>=tne) break;

        //max row
        for(int j=maxc ; j>=minc ;j--){
            cout<<arr[maxr][j]<<" ";
            count++;
        }
        maxr--;
        if(count>=tne) break;

        //min column
        for(int i=maxr ; i>=minr ;i--){
            cout<<arr[i][minc]<<" ";
            count++;
        }
        minc++;
        if(count>=tne) break;
    }
return 0;
}