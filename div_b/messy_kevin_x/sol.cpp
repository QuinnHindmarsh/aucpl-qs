#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1);  // 1 indexed

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        a[u].push_back(v);
    }

    int start, end;
    cin >> start >> end;

    queue<pair<int, int>> q;
    vector<int> seen(n + 1, -1);
    q.push({start, 1});

    seen[start] = 1;

    while (!q.empty()) {
        auto [node, cnt] = q.front();
        q.pop();

        if (node == end) break;

        for (int edge : a[node]) {
            if (seen[edge] != -1) continue;

            seen[edge] = cnt + 1;
            q.push({edge, cnt + 1});
        }
    }

    cout << seen[end] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
