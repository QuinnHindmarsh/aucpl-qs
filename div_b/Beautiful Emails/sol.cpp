#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    int ans = 0;

    for (int j = 1; j <= 9; j++) {
        // build j, jj, jjj, ... arithmetically; stop once it exceeds n
        for (unsigned long long rep = j; rep <= (unsigned long long)n; rep = rep * 10 + j) {
            if (n % rep == 0) ++ans;
        }
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
