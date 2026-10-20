#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool in_bounds(int r, int c, int n, int m) { return (0 <= r) && (r < n) && (0 <= c) && (c < m); }

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (string& x : a) cin >> x;
    vector<vector<bool>> seen(n, vector(m, false));
    queue<tuple<int, int, int>> q;
    pair<int, int> moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    pair<int, int> tar;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'p')
                tar = {i, j};
            else if (a[i][j] == '@') {
                q.push({i, j, 0});
                seen[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [r, c, x] = q.front();
        q.pop();

        if (r == tar.first && c == tar.second) {
            cout << x << '\n';
            return;
        }

        for (auto [rc, cc] : moves) {
            int rt = r + rc;
            int ct = c + cc;

            if (in_bounds(rt, ct, n, m) && !seen[rt][ct] && a[rt][ct] != '#') {
                seen[rt][ct] = true;
                q.push({rt, ct, x + 1});
            }
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
