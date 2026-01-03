#include <bits/stdc++.h>
using namespace std;

struct Event {
    double time;
    int type;   // +1 = arrival, -1 = departure
};

bool cmp(const Event &a, const Event &b) {
    if (a.time == b.time)
        return a.type < b.type;   // departure first
    return a.time < b.time;
}

int minPlatforms(vector<double> &arrival, vector<double> &departure) {
    int n = arrival.size();
    vector<Event> events;

    for (int i = 0; i < n; i++) {
        events.push_back({arrival[i], +1});
        events.push_back({departure[i], -1});
    }

    sort(events.begin(), events.end(), cmp);

    int curr = 0, ans = 0;

    for (auto &e : events) {
        curr += e.type;
        ans = max(ans, curr);
    }

    return ans;
}

int main() {
    vector<double> arrival = {9.00, 9.40, 9.50, 11.00, 15.00, 18.00};
    vector<double> departure = {9.10, 12.00, 11.20, 11.30, 19.00, 20.00};

    cout << minPlatforms(arrival, departure) << endl;
    return 0;
}
