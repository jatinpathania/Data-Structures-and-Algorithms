#include <vector>
#include <iostream>
using namespace std;

class LemonadeStand {
public:
    bool lemonadeChange(vector<int>& bills){
        int fiveDol=0;
        int tenDol= 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                fiveDol++;
            }
            else if(bills[i] == 10){
                if(fiveDol){
                    tenDol++;
                    fiveDol--;
                }
                else return false;
            }
            else {
                if(tenDol && fiveDol){
                    tenDol--;
                    fiveDol--;
                }
                else if(fiveDol>=3){
                    fiveDol-=3;
                }
                else return false;  
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queue of customers: ";
    for (int bill : bills) cout << bill << " ";
    cout << endl;
    LemonadeStand stand;
    bool ans = stand.lemonadeChange(bills);
    if(ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}