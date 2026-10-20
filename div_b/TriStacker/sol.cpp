#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    ll temp;

    for (ll i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    };
    ll i = 1;

    while (sum > 0) {
        sum -= i;
        ++i;
    };

    if (sum == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
