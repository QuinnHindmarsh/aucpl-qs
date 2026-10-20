#include <bits/stdc++.h>
using namespace std;

int bfs(const vector<vector<int>>& adj, int src, int dst) {
    queue<int> q;
    vector<int> dist(adj.size(), -1);
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == dst) break;

        for (int neigh : adj[node]) {
            if (dist[neigh] != -1) continue;
            dist[neigh] = dist[node] + 1;
            q.push(neigh);
        }
    }
    return dist[dst];
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int dest;
        cin >> dest;
        adj[i].push_back(dest);
    }

    vector<string> names(m);
    for (string& s : names) cin >> s;

    vector<tuple<int, int, string>> reached;
    vector<string> stuck;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int d = bfs(adj, x, n);
        if (d == -1)
            stuck.push_back(names[i]);
        else
            reached.emplace_back(d, i, names[i]);
    }

    sort(reached.begin(), reached.end());

    for (size_t k = 0; k < reached.size(); k++) {
        if (k) cout << ' ';
        cout << get<2>(reached[k]);
    }
    cout << '\n';

    for (size_t k = 0; k < stuck.size(); k++) {
        if (k) cout << ' ';
        cout << stuck[k];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
