#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;

    unordered_map<int, int> first;
    ll mx = -1;

    for (int i = 0; i < n; i++) {
        auto it = first.find(a[i]);

        if (it != first.end()) {
            mx = max(mx, (i - (it->second)) * a[i]);
        } else {
            first[a[i]] = i;
        }
    }

    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
