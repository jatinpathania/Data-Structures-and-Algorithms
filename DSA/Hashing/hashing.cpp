#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0 ; i<n ;i++){
        cin>>arr[i];
    }
    //precompute
    int hash[13]={0};     // coz we need to go till 12th index
    for(int i= 0; i<n ;i++){
        hash[arr[i]] +=1;        //acts as a count variable to count the no of occurences
    }

    cout<<"Enter the no of queries: ";
    int q;
    cin>>q;
    while(q--){
        cout<<"Enter the query: ";
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
return 0;
}

// There are three methods 
// 1. Division method   ..linear chaining
// 2. Folding method
// 3. Mod square method

//Collision
// If all values leave for ex. 8 after modulus of 10 .. they all leave 8 as remainder ... which means all are stored in one hash .. and all other 
// spaces are left blank .then this causes a collision