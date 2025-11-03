#include<bits/stdc++.h>
using namespace std;

struct Item{
    int weight;
    int value;
};

bool cmp(Item a, Item b){
    double r1= (double)a.value/a.weight;
    double r2= (double)b.value/b.weight;
    return r1>r2;       // dec order means weights with max value per weight should be taken first greedly
}

int maxProfit(vector<int>& weights, vector<int>& values, int capacity){
    int n= weights.size();
    vector<Item> items(n);

    for(int i=0; i<n ;i++){
        items[i]= {weights[i], values[i]};
    }

    sort(items.begin(), items.end(), cmp);
    double totalValue= 0.0;

    for(int i=0; i<n; i++){
        if(items[i].weight <= capacity){
            capacity-= items[i].weight;
            totalValue+= items[i].value;
        }
        else{
            double partWeight= (double)capacity/items[i].weight;
            double currValue= items[i].value;
            totalValue+= currValue*partWeight;
            break;      // after this rem part fits in capacity.. just break and leave
        }
    }
    return (int)totalValue;
}

int main(){
    vector<int> weights={20,10,30};
    vector<int> values= {100,60,120};
    int capacity= 50;
    int res= maxProfit(weights,values,capacity);
    cout<<"The max profit earned can be "<<res<<endl;
}