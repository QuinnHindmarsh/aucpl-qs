#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check_valid(int r, int c, int n, int m) { return 0 <= r && r < n && 0 <= c && c < m; }

void solve() {
    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;
    vector<string> a(n);
    for (string& x : a) cin >> x;

    q.push(pair(0, 0));

    vector<pair<int, int>> modifiers = {pair(0, 1), pair(0, -1), pair(1, 0), pair(-1, 0)};

    vector<vector<bool>> seen(n, vector<bool>(m, false));

    if (a[0][0] == '*') {
        cout << "FAIL" << "\n";
        return;
    }
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == n - 1 && c == m - 1) {
            cout << "SUCCESS" << '\n';
            return;
        }

        for (const auto& [x, y] : modifiers) {
            int temp_r = r + x;
            int temp_c = c + y;

            if (check_valid(temp_r, temp_c, n, m) && a[temp_r][temp_c] != '*' &&
                !seen[temp_r][temp_c]) {
                q.push(pair(temp_r, temp_c));
                seen[temp_r][temp_c] = true;
            }
        }
    }
    cout << "FAIL" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
