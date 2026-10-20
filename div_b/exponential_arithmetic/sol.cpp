#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll t, b;
    cin >> t >> b;

    ll cnt = 0;

    if (b == 1) {
        cnt = t;
        t = 0;
    }

    ll p = 1;
    while (p * b <= t) p *= b;

    while (t > 0) {
        if (p <= t) {
            cnt += t / p;
            t %= p;
        }
        p /= b;
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
