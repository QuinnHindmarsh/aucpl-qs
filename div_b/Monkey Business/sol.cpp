#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int m[3] = {a, b, c};

    int days = 0;

    while (m[0] > 0 && m[1] > 0 && m[2] > 0) {
        sort(m, m + 3);

        if ((m[0] != m[1]) or (m[1] != m[2])) {
            m[0]++;
            m[2]--;
        }
        m[0]--;
        m[1]--;
        m[2]--;

        days++;
    }

    cout << days << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
