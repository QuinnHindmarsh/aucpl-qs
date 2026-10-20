#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    vector<Node*> children;
    int colour;
};

void solve() {
    int n;
    cin >> n;

    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        int colour;
        cin >> colour;
        a[i] = Node();
        a[i].colour = colour;
    }

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        a[parent].children.emplace_back(&a[i]);
    }

    unordered_map<int, int> level_to_colour;
    queue<pair<Node*, int>> q;
    // index, level

    q.push({&a[0], 0});

    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();

        auto it = level_to_colour.find(level);

        if (it != level_to_colour.end() && it->second != (*node).colour) {
            cout << "Invalid" << "\n";
            return;
        }

        level_to_colour[level] = (*node).colour;

        for (Node* child : (*node).children) {
            q.push({child, level + 1});
        }
    }

    cout << "Valid" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
