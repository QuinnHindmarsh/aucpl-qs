#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, p, s;
    cin >> n >> p >> s;
    int c1, c2;
    vector<int> d(n);
    for (int& x : d) cin >> x;
    cin >> c1 >> c2;
    int offset = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] == c1) {
            offset = (i + 1) - s;
            if (offset < 0) {
                offset += n;
            }
        }
    }

    vector<pair<int, int>> ans(p);

    for (int i = 0; i < p; i++) {
        int first_idx = (i + offset) % n;
        int second_idx = (i + offset + p) % n;

        ans[i].first = d[first_idx];
        ans[i].second = d[second_idx];
    }

    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
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
