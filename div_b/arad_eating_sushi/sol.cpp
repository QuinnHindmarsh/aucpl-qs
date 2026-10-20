#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;

    ll sm = accumulate(a.begin(), a.end(), 0LL);

    ll cur = 0;

    int l = 0, r = 0, mn = numeric_limits<int>::max();

    while (r < n) {
        while (!(sm * m <= cur * 100) && r < n) {
            cur += a[r];
            r++;
        }
        while (sm * m <= cur * 100 && l < r) {
            mn = min(mn, r - l);
            cur -= a[l];
            ++l;
        }
    }

    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
