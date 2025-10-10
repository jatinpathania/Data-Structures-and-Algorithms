#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    vector<string> items = {"apple", "banana", "orange", "grapes"};
    vector<double> rates = {50.0, 20.0, 30.0, 40.0};

    vector<string> soldItems = {"banana", "apple", "grapes", "orange", "apple"};
    vector<double> soldRates = {20.0, 55.0, 40.0, 25.0, 50.0};

    unordered_map<string, double> priceMap;
    for (size_t i = 0; i < items.size(); ++i) {
        priceMap[items[i]] = rates[i];
    }

    int mismatchCount = 0;

    for (size_t i = 0; i < soldItems.size(); ++i) {
        string item = soldItems[i];
        double soldRate = soldRates[i];

        if (priceMap.find(item) != priceMap.end()) {
            if (priceMap[item] != soldRate) {
                mismatchCount++;
            }
        } else {
            mismatchCount++;
        }
    }

    cout << "Number of mismatched sold items: " << mismatchCount << endl;

    return 0;
}
