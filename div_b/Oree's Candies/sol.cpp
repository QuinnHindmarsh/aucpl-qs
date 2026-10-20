#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    unordered_map<int, int> mp;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    const int INF = 1e9;
    vector<int> dp(q + 1, INF);
    dp[0] = 0;

    for (int s = 1; s <= q; ++s) {
        for (int x : a) {
            if (x <= s) {
                dp[s] = min(dp[s], dp[s - x] + 1);
            }
        }
    }

    cout << (dp[q] == INF ? -1 : dp[q]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
