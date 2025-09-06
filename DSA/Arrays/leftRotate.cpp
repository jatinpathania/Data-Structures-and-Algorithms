#include <iostream>
using namespace std;

// or we can simply use inbuilt reverse function in cpp
void Reverse(int arr[], int start, int end){
  while(start <= end){
    int temp= arr[start];
    arr[start]= arr[end];
    arr[end]= temp;
    start++;
    end--;
  }
}

void Rotateeletoleft(int arr[], int n, int k){
  Reverse(arr, 0, k-1);
  Reverse(arr, k, n-1);
  Reverse(arr, 0, n-1);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 2;
  k= k%n;
  Rotateeletoleft(arr, n, k);
  cout << "After Rotating the k elements to left ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}



// brute force

// #include <iostream>
// using namespace std;

// int main()
// {
//   int arr[] = {1, 2, 3, 4, 5, 6, 7};
//   int n = 7;
//   int k = 2;
//   k= k%n;
//   int temp[k];
//   for(int i=0; i< k ;i++){
//     temp[i]= arr[i];
//   } 
  
//   //shifting
//   for(int i= k ; i<n ; i++){
//     arr[i-k]= arr[i];
//   }

//   //putting temp back
//   for(int i= n-k ; i<n ;i++){
//     arr[i]= temp[i - (n-k)];  // or else we can use simply j=0 if don't want to do mathematics
//   }


//   //simply print
//   for(int i=0; i<n ;i++) cout<< arr[i]<<" ";
//   return 0;
// }
