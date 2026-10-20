#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll cur = 0;
    int last_mn;

    cin >> last_mn;
    for (int i = 1; i < n; i++) {
        int cost;
        cin >> cost;

        if (cost > last_mn) {
            cur += cost - last_mn;
            last_mn = cost;
        }
        last_mn = min(last_mn, cost);
    }

    cout << cur - last_mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
