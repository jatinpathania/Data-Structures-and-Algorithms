#include<bits/stdc++.h>
using namespace std;

void solve(int remaining, vector<int>& cuts, vector<int>& currentCuts, int& maxCuts){
    if(remaining== 0){
        maxCuts= max(maxCuts, (int)currentCuts.size());
        return;
    }

    if(remaining< 0) return;

    for(int i= 0; i< cuts.size(); i++){
        currentCuts.push_back(cuts[i]);
        solve(remaining- cuts[i], cuts, currentCuts, maxCuts);
        currentCuts.pop_back();
    }
}

int solver(int n, vector<int>& cuts){
    int maxCuts= 0;
    vector<int> currentCuts;
    solve(n, cuts, currentCuts, maxCuts);
    return maxCuts;
}

int cutTheRopes(int n, vector<int>& cuts){
    return solver(n, cuts);
}

int main(){
    vector<int> cuts1= {2, 3, 1};
    int n1= 5;
    int result1= cutTheRopes(n1, cuts1);
    cout<< "For n= " << n1 << " with cuts= { ";
    for(int i= 0; i< cuts1.size(); i++){
        cout<< cuts1[i];
        if(i< cuts1.size()- 1) cout<< ", ";
    }
    cout<< " } => " << result1 << endl;

    vector<int> cuts2= {2, 3, 1};
    int n2= 10;
    int result2= cutTheRopes(n2, cuts2);
    cout<< "For n= " << n2 << " with cuts= { ";
    for(int i= 0; i< cuts2.size(); i++){
        cout<< cuts2[i];
        if(i< cuts2.size()- 1) cout<< ", ";
    }
    cout<< " } => " << result2 << endl;

    return 0;
}