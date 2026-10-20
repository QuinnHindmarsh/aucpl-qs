#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<bool> b(n);

    for (ll& x : a) cin >> x;

    ll last1 = numeric_limits<float>::min();
    ll last2 = numeric_limits<float>::min();

    for (int i = 0; i < n; i++) {
        b[i] = (last2 > last1 && last1 > a[i]);
        last2 = last1;
        last1 = a[i];
    }

    ll ans = 0;
    ll l = 0;

    for (int i = 0; i < n; i++) {
        if (b[i]) {
            ans += (i - l) * (i - l + 1) / 2;
            l = i - 1;
            ans -= 1;
        }
    }

    ans += (n - l) * (n - l + 1) / 2;
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
