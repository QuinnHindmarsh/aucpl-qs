#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int l = 0;
    int r = 0;
    unordered_map<char, int> mp;
    int mx = 0;

    while (r < (int)s.length()) {
        auto it = mp.find(s[r]);

        if (it != mp.end() && it->second >= l) {
            l = it->second + 1;
        }
        mp[s[r]] = r;
        ++r;
        mx = max(mx, r - l);
    }

    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
