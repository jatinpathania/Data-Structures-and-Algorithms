#include <bits/stdc++.h>
using namespace std;

//Complexity- O(n log n)
int minPlatforms(vector<double> &arrival, vector<double> &departure) {
    int n= arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int i=1; //arrival poitner
    int j=0; //departure pointer
    int platforms= 1;
    int maxPlatforms=1;
    while(i<n && j<n){
        if(arrival[i] <= departure[j]){
            platforms++;
            i++;
            maxPlatforms= max(maxPlatforms, platforms);
        }
        else{
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

int main() {
    vector<double> arrival = {9.00, 9.40, 9.50, 11.00, 15.00, 18.00};
    vector<double> departure = {9.10, 12.00, 11.20, 11.30, 19.00, 20.00};

    cout << minPlatforms(arrival, departure) << endl;
    return 0;
}
