#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);  // 1 indexed
    queue<int> q;
    vector<int> in_degree(n + 1);
    vector<bool> visted(n + 1, false);
    visted[0] = true;  // 1 indexed, node 0 doesnt exist

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v] += 1;
    }

    for (int i = 1; i <= n; i++) {  // skip node 0 which doesnt exist
        if (in_degree[i] == 0) {
            q.push(i);
            visted[i] = true;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int out_going : adj[node]) {
            in_degree[out_going]--;
            if (in_degree[out_going] == 0) {
                q.push(out_going);
                visted[out_going] = true;
            }
        }
    }

    if (ranges::all_of(visted, identity{})) {
        cout << "Shahid can let Jason in." << "\n";
    } else {
        cout << "Jason is sleeping outside tonight." << "\n";
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
