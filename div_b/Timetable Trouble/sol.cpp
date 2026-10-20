#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll tc = 0;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int x, y, z;
        cin >> x >> y >> z;
        ll b, c;
        cin >> b >> c;
        int req_classes;

        if (y != 0) {
            req_classes = (x % y == 0) ? x / y : x / y + 1;
        } else {
            req_classes = (x == 0) ? 0 : numeric_limits<int>::max();
        }

        if (req_classes > 100 || (req_classes * c) > b) {
            cout << name << " is cancelled!" << '\n';
        } else {
            tc += req_classes * c;
            cout << name << " " << req_classes - z << '\n';
        }
    }

    cout << "Total cost is: " << tc << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
