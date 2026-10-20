#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> adj(n + 1);
    int count = 0;
    queue<int> q;
    vector<bool> seen(n + 1);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        q.push(x);
        seen[x] = true;
        count++;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (seen[neighbour]) continue;
            seen[neighbour] = true;

            q.push(neighbour);
            count++;
        }
    }

    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
