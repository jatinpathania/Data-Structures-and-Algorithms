#include <bits/stdc++.h>
using namespace std;

vector <int> FindUnion(int arr1[], int arr2[], int n, int m){
    vector<int> unionArr;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!= arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!= arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    //leftovers
    while(j<m){
        if(unionArr.size()==0 || unionArr.back()!= arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    while(i<n){
        if(unionArr.size()==0 || unionArr.back()!= arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    return unionArr;
}

int main(){
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
    vector < int > Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union) cout << val << " ";
    return 0;
}