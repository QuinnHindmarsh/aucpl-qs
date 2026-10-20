#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n = 6;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    ll num = a[0] * a[5];
    ll den = a[0] * a[5] + a[4] * a[1];

    cout << fixed << setprecision(4) << (double)num / den << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
