#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;

    ll mn1 = numeric_limits<ll>::max();
    ll mn2 = numeric_limits<ll>::max();

    for (ll h : a) {
        if (h < mn1) {
            mn2 = mn1;
            mn1 = h;
        } else if (h < mn2) {
            mn2 = h;
        }
    }

    if ((a[0] == mn1 && a[n - 1] == mn2) || (a[0] == mn2 && a[n - 1] == mn1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
