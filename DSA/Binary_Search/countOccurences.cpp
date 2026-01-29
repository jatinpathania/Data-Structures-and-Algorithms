#include <bits/stdc++.h>
using namespace std;

//If interviewer doesnn't know about lower and upper bound
int firstOccurence(vector<int>& v, int n, int k){
    int low=0, high= n-1;
    int first= -1;
    while(low<= high){
        int mid= low+ (high-low)/2;
        if(v[mid] == k){
            first= mid;
            high= mid-1;
        }
        else if(v[mid] <k){
            low= mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return first;
}
int lastOccurence(vector<int>& v, int n, int k){
    int low=0, high= n-1;
    int last= -1;
    while(low<= high){
        int mid= low+ (high-low)/2;
        if(v[mid] == k){
            last= mid;
            low= mid+1;
        }
        else if(v[mid] <k){
            low= mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return last;
}


pair<int,int> firstAndLastPosition(vector<int>& v, int n, int k){
    int first= firstOccurence(v, n, k);
    if(first== -1) return {-1,-1};
    int last= lastOccurence(v, n, k);
    return {first, last};
}

int countOccurences(vector<int>& v, int n, int key){
    pair<int,int> ans= firstAndLastPosition(v, n, key);
    if(ans.first ==-1) return 0;
    return ans.second- ans.first+1;
}


int main() {
    int n = 7;
    int key = 13;
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};
    int res= countOccurences(v,n, key);
    cout<<"The number of occurences of "<<key<<" are "<<res<<"\n";
    return 0;
}
