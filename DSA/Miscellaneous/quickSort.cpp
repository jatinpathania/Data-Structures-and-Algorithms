#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int A[],int low,int high){
    int pivot=A[low];
    int i= low+1;
    int j= high;
    while(i<=j){
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[low],&A[j]);
    return j;
}

void quickSort(int A[],int low,int high){
    if(low<high){
    int partitionIndex= partition(A,low,high);
    quickSort(A,low,partitionIndex-1);    //sort left subarray
    quickSort(A,partitionIndex+1,high);   //sort right subarray
    }
}
void printArray(int A[],int n){
    for(int i=0 ; i<n ;i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

int main()
{  
    int arr[]={2,4,3,9,1,4,8,7,5,6};
    int n= sizeof(arr)/sizeof(int);
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printArray(arr,n);
return 0;
}

// time complexity
//Best    O(n log n)
//Worst   O(n²)
