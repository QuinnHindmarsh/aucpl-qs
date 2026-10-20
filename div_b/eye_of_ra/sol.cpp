#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int pupils = 0;

    for (char ch : s) {
        if (ch == '6') {
            ++pupils;
        } else if (pupils > 0) {
            --pupils;
            ++ans;
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
