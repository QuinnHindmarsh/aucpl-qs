#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll a, b;
    cin >> a >> b;

    unsigned long long diff_x = (x1 > x2) ? (x1 - x2) : (x2 - x1);
    unsigned long long diff_y = (y1 > y2) ? (y1 - y2) : (y2 - y1);

    unsigned long long days_x = diff_x / a;
    if (diff_x % a != 0) ++days_x;

    unsigned long long days_y = diff_y / b;
    if (diff_y % b != 0) ++days_y;

    cout << max(days_x, days_y) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
