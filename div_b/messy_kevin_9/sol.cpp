#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    stack<pair<ll, ll>> s;
    vector<ll> ans(n, -1);

    for (ll& x : a) cin >> x;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first < a[i]) {
            s.pop();
        }

        if (!s.empty()) {
            ans[i] = s.top().second;
        }

        s.emplace(a[i], i + 1);
    }

    for (int num : ans) {
        cout << num << "\n";
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
