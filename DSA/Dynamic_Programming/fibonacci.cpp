//Recursion
// #include <bits/stdc++.h>
// using namespace std;

// //Time complexity- O(n), Space- O(n)+O(n)
// int fibonacci(int n,vector<int>& dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]= fibonacci(n-1,dp)+ fibonacci(n-2,dp); 
// }

// int main(){
//     int n;
//     cout<<"Enter no: ";
//     cin>>n;
//     vector<int> dp(n+1, -1);
//     cout<<fibonacci(n,dp);
// }


//Tabulation-

// #include <bits/stdc++.h>
// using namespace std;

// //Time complexity- O(n), Space- O(n)
// int main(){
//     int n;
//     cout<<"Enter no: ";
//     cin>>n;
//     vector<int> dp(n+1);
//     dp[0]=0;
//     if(n>=1) dp[1]=1;
//     for(int i=2; i<=n ;i++){
//         dp[i]= dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n];
//     return 0;
// }



//Space optimised way
#include <bits/stdc++.h>
using namespace std;

//Time complexity- O(n), Space- O(1)

int main(){
    int n;
    cout<<"Enter no: ";
    cin>>n;
    int prev2=0;
    int prev=1;
    for(int i=1; i<=n; i++){
        int curr= prev2+ prev;
        prev2= prev;
        prev= curr;
    } 
    cout<<prev;
}
