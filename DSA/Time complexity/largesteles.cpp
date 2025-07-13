// #include <iostream>
// using namespace std;
// int main() {
//     int arr[] = {5,9,8,7,6,4,12,11,1,13};
//     int sum=0;
//     int len= sizeof(arr)/sizeof(arr[0]);
//     for(int i=0 ; i<len; i++){
//         sum+=arr[i];
//     }
//     cout<<"The average of array is "<<sum/len;
//     return 0;
// }

//Largest element

// #include <iostream>
// using namespace std;
// int main() {
//     int arr[] = {5,9,8,7,6,4,12,11,1,13};
//     int max=arr[0];
//     int len= sizeof(arr)/sizeof(arr[0]);
//     for(int i=0 ; i<len; i++){
//         if(max<arr[i]){
//             max=arr[i];
//         }
//     }
//     cout<<"The largest element from array is "<<max;
//     return 0;
// }


//   Second largest

// #include <iostream>
// using namespace std;
// int main() {
//     int arr[] = {5,9,8,7,6,4,12,11,1,13};
//     int max=arr[0];
//     int secmax= arr[0];
//     int len= sizeof(arr)/sizeof(arr[0]);
//     for(int i=0 ; i<len; i++){
//         if(max<arr[i]){
//             secmax=max;
//             max=arr[i];
//         }
//         else if(arr[i]>secmax && arr[i]<max){
//             secmax=arr[i];
//         }
//     }
//     cout<<"The Second largest element from array is "<<secmax;
//     return 0;
// }


// Third largest

#include <iostream>
using namespace std;
int main() {
    int arr[] = {5,9,8,7,6,4,12,11,1,13};
    int max=arr[0];
    int secmax= arr[0];
    int thirdmax=arr[0];
    int len= sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i<len; i++){
        if(max<arr[i]){
            thirdmax=secmax;
            secmax=max;
            max=arr[i];
        }
        else if(arr[i]<max && arr[i]>secmax){
            thirdmax=secmax;
            secmax= arr[i];
        }
        else if(arr[i]<secmax && arr[i]>thirdmax){
            thirdmax= arr[i];
        }
        
    }
    cout<<"The Third largest element from array is "<<thirdmax;
    return 0;
}