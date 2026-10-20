#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);  // 1 indexed
    queue<pair<int, ll>> q;
    vector<int> in_degree(n + 1);
    vector<int> cost(n + 1);
    vector<ll> cost_in(n + 1);

    for (int i = 1; i <= n; i++) {  // 1 indexed
        int p, c;
        cin >> p >> c;
        // p = parent
        // c = duration
        cost[i] = c;

        if (p == i) {  // no parent
            q.emplace(i, cost[i]);
        } else {
            adj[p].push_back(i);
            in_degree[i] += 1;
        };
    }
    ll mx = 0;

    while (!q.empty()) {
        auto [node, c] = q.front();
        q.pop();

        for (int out_going : adj[node]) {
            in_degree[out_going]--;
            cost_in[out_going] = max(cost_in[out_going], c);

            if (in_degree[out_going] == 0) {
                ll total_cost = cost_in[out_going] + cost[out_going];
                mx = max(mx, total_cost);
                q.emplace(out_going, total_cost);
            }
        }
    }

    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
