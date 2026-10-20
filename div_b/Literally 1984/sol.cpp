#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll mn = numeric_limits<ll>::max();

    for (int a = 1; a <= (int)(sqrt(n) + 1); a++) {
        int b = n / a;
        if (b * a != n) {
            continue;
        }

        ll temp = (b - 1) * a;
        temp += (a - 1) * b;
        temp += 2 * a;
        temp += 2 * b;

        mn = min(mn, temp);
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
