#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<ll, 6>> a(n);
    for (auto& x : a) { for (ll& y : x) cin >> y; }

    int mx_solve = -1;
    ll mn_time = 0;

    for (auto& arr : a) {
        int solved = 0;
        ll time = 0;

        for (ll num : arr) {
            if (num != -1) {
                time += num;
                ++solved;
            }
        }

        if (solved > mx_solve || (solved == mx_solve && time < mn_time)) {
            mn_time = time;
            mx_solve = solved;
        }
    }





    cout << mx_solve << ' ' << mn_time << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
