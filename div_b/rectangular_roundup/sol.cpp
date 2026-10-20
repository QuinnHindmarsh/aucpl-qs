#include <bits/stdc++.h>
#include <limits>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector < pair<int, int >> a(n);
    for (auto& [x, y] : a) cin >> x >> y;

    int mx_x, mx_y; mx_x = mx_y = 0;
    int mn_x, mn_y; mn_x = mn_y = numeric_limits<int>::max();

    for (auto& [x, y] : a) {
        mx_x = max(mx_x, x);
        mx_y = max(mx_y, y);
        mn_x = min(mn_x, x);
        mn_y = min(mn_y, y);


    }

    cout << mn_x << ' ' << mn_y << "\n";
    cout << mn_x << ' ' << mx_y << "\n";
    cout << mx_x << ' ' << mx_y << "\n";
    cout << mx_x << ' ' << mn_y << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

    return 0;
}
