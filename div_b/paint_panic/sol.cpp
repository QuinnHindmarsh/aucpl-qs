#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    priority_queue<tuple<int, int, int>> maxh;
    // prioty, age, id
    int counter = 0;

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;

        if (token == "print") {
            if (maxh.empty()) {
                cout << "ERROR\n";
            } else {
                auto [_priotiy, _age, id] = maxh.top();
                maxh.pop();
                cout << id << "\n";
            }
        } else {
            int priority, id;
            id = stoi(token);
            cin >> priority;
            maxh.emplace(priority, counter, id);
            counter--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
