#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool valid(int i, int j, int r, int c) { return 0 <= i && i < r && 0 <= j && j < c; }

bool bfs(vector<vector<char>>& m, int i, int j, int r, int c) {
    queue<pair<int, int>> q;
    q.emplace(i, j);
    array<pair<int, int>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [a, b] : dirs) {
            int ti = x + a;
            int tj = y + b;
            if (!valid(ti, tj, r, c)) continue;
            if (m[ti][tj] == 'E') return true;
            if (m[ti][tj] == '.') {
                m[ti][tj] = 'v';
                q.emplace(ti, tj);
            }
        }
    }
    return false;
}

void solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> m(r, vector<char>(c));

    pair<int, int> start;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            m[i][j] = ch;

            if (ch == '$') {
                start.first = i;
                start.second = j;
            }
        }
    }

    if (bfs(m, start.first, start.second, r, c)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
