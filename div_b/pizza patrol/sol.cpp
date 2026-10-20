#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        ll tar;
        cin >> tar;

        if (s.find(tar) != s.end()) {
            continue;
        }

        auto it = s.upper_bound(tar);
        if (it != s.end()) {
            cout << "A greedy member at " << tar << " has pushed in front of the member at ";
            cout << *it << ", this is terrible" << "\n";
        }
        s.insert(tar);
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
