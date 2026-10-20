#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, x;
    cin >> n >> x;
    int ans = 0;
    ll cur_sum = 0;
    int l = 0;

    vector<ll> a(n);
    for (ll& y : a) cin >> y;

    if (x == 0) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        cur_sum += a[i];
        while (cur_sum > x) {
            cur_sum -= a[l];
            ++l;
        }
        if (cur_sum == x) ++ans;
    }

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
