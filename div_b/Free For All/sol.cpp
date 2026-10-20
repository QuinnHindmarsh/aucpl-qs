#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> pos;
    unordered_map<int, int> neg;

    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        int n = r - c;
        int p = r + c;
        if (pos.find(p) == pos.end()) {
            pos[p] = 0;
        }
        if (neg.find(n) == pos.end()) {
            neg[n] = 0;
        }
        ++pos[p];
        ++neg[n];
    }

    int ans = 0;

    for (const auto& [_, sm] : pos) {
        ans += ((sm - 1) * sm) / 2;
    }

    for (const auto& [_, sm] : neg) {
        ans += ((sm - 1) * sm) / 2;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
