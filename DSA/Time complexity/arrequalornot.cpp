// #include <iostream>
// using namespace std;
// void selectionSort(int arr[],int n){
//     for (int i = 0; i <n-1; i++){      //n-1 passes
//         int min= arr[i];            //not arr[0] because we are taking first element for each pass of the unsorted arr
//         int minidx = i;
//         for(int j=i ; j<=n-1 ;j++){
//             if(arr[j]<min){
//                 min = arr[j];
//                 minidx = j;
//             } 
//         }
//         //swap the min and first element of unsorted part
//         //swap minidx and i
//         int temp= arr[minidx];
//         arr[minidx] = arr[i];
//         arr[i] = temp;
//     }
// }
// int main() {
//     int n,m;
//     cout<<"Enter size of array 1: ";
//     cin>>n;
//     cout<<"Enter size of array 2: ";
//     cin>>m;
//     int arr1[n],arr2[m];
//     cout<<"Enter elements of array 1: ";
//     for(int i=0 ; i<n; i++){
//         cin>>arr1[i];
//     }
//     cout<<"Enter elements of array 2: ";
//     for(int i=0 ; i<m; i++){
//         cin>>arr2[i];
//     }
    
//     // first we sort and then we compare
//     selectionSort(arr1,n);
//     selectionSort(arr2,m);

//     //compare
//     if(n!=m) cout<<"Not equal";
//     else{
//     bool flag= true;
//     for(int i=0,j=0 ; i<n && j<m; i++,j++){
//         if(arr1[i]!=arr2[j]){
//             flag = false;
//             break;
//         }
//     }
//     if(flag) cout<<"Equal"<<endl;
//     else cout<<"Not Equal"<<endl;
//     }
    //O(n^2 )





    #include <iostream>
    using namespace std;

    bool compareArraysXOR(int arr1[], int arr2[], int n, int m) {
    // If arrays are not of the same size, return false
    if (n != m) {
        return false;
    }

    int xorResult = 0;
    for (int i = 0; i < n; i++) {
        xorResult ^= arr1[i];
        xorResult ^= arr2[i];
    }

    // If XOR result is 0, arrays are equal
    return xorResult == 0;
    }

    int main() {
    int n, m;
    cout << "Enter size of array 1: ";
    cin >> n;
    cout << "Enter size of array 2: ";
    cin >> m;
    
    int arr1[n], arr2[m];
    
    cout << "Enter elements of array 1: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of array 2: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    
    if (compareArraysXOR(arr1, arr2, n, m)) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }
    
    return 0;
    }

    //O(nlogn)


    // int arr1[]= {11,12,13};
    // int arr2[]= {13,11,12};

    // // ex2 
    // int arr3[]={1,2,2};
    // int arr4[]={2,1,2};
    
    // //ex3
    // int arr5[]={5,6,7,8,9};
    // int arr6[]={5,6,7,8,10};

    // //ex4
    // int arr7[]={5,6,7};
    // int arr8[]={5,6};

    //do it by
    // brute force
    // O(n^2)

    // sorting
    // O(nlogn)

    // optimal
    // O(n)
    // hint ; xor