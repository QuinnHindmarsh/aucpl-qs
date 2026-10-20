#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    ll mx_indervidual = 0;
    ll sm = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mx_indervidual = max(mx_indervidual, x);
        sm += x;
    }
    ll ans = max(mx_indervidual, (ll)(sm + 1) / 2);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
