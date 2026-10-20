#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    int t;
    cin >> t;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector<ll> dp(t + 1, 0);  // 1 indexed
    dp[0] = 1;

    for (ll drink : a) {
        for (int s = drink; s <= t; s++) {
            dp[s] += dp[s - drink];
        }
    }

    cout << dp[t] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
