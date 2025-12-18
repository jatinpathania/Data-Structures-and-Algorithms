// Sheet ques
//Time complexity- O(n log n)+ O(n)

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
class Solution {
public:
    bool static cmp(Item a, Item b){
        double r1= (double)a.value/(double) a.weight;
        double r2= (double)b.value/(double) b.weight;
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr+n ,cmp);
        double totalValue=0;
        for(int i=0; i<n ; i++){
            if(arr[i].weight <= W){
                totalValue+= arr[i].value;
                W-= arr[i].weight;
            }
            else{
                totalValue+= ((double)arr[i].value/(double)arr[i].weight)*W;
                break;
            }
        }
        return totalValue;
    }
};

int main() {
    int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}

// Class logic
// #include<bits/stdc++.h>
// using namespace std;

// struct Item{
//     int weight;
//     int value;
// };

// bool cmp(Item a, Item b){
//     double r1= (double)a.value/a.weight;
//     double r2= (double)b.value/b.weight;
//     return r1>r2;       // dec order means weights with max value per weight should be taken first greedly
// }

// int maxProfit(vector<int>& weights, vector<int>& values, int capacity){
//     int n= weights.size();
//     vector<Item> items(n);

//     for(int i=0; i<n ;i++){
//         items[i]= {weights[i], values[i]};
//     }

//     sort(items.begin(), items.end(), cmp);
//     double totalValue= 0.0;

//     for(int i=0; i<n; i++){
//         if(items[i].weight <= capacity){
//             capacity-= items[i].weight;
//             totalValue+= items[i].value;
//         }
//         else{
//             double partWeight= (double)capacity/items[i].weight;
//             double currValue= items[i].value;
//             totalValue+= currValue*partWeight;
//             break;      // after this rem part fits in capacity.. just break and leave
//         }
//     }
//     return (int)totalValue;
// }

// int main(){
//     vector<int> weights={20,10,30};
//     vector<int> values= {100,60,120};
//     int capacity= 50;
//     int res= maxProfit(weights,values,capacity);
//     cout<<"The max profit earned can be "<<res<<endl;
// }