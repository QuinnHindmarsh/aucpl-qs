#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int energy = 0;

    vector<pair<char, int>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;

    for (auto [x, y] : a) {
        if (x == 'W') {
            energy -= y;
            if (energy < 0) {
                break;
            }
        } else if (x == 'B') {
            energy += y;

        } else {
            energy += 2 * y;
        }
    }

    cout << energy << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
