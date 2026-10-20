#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> up(n);
    vector<string> down(n);

    for (string& s : up) cin >> s;
    for (string& s : down) cin >> s;
    int ans = 0;

    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                unordered_set<string> up_set;
                ans++;

                for (const string& s : up) {
                    string temp = {s[i], s[j], s[k]};
                    up_set.insert(temp);
                }

                for (const string& s : down) {
                    string temp = {s[i], s[j], s[k]};
                    if (up_set.contains(temp)) {
                        --ans;
                        break;
                    }
                }
            }
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
