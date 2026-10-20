#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    cout << min(n, min((a + b) - n, min(a, b))) + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
