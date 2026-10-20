#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*

zeros where 0 after it
/
zeros where 0 after it + zeros where 1 after it

zeros+1/ 1s
*/
void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;

    ll adj_zeros = 0;
    ll total_zeros = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ++total_zeros;
            if ((i == (int)(a.size() - 1) && a[0] == 0) ||
                (i != (int)(a.size() - 1) && a[i + 1] == 0)) {
                ++adj_zeros;
            }
        }
    }

    if (adj_zeros * n >= total_zeros * total_zeros) {
        cout << "Shoot" << '\n';
    } else {
        cout << "Spin" << '\n';
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
