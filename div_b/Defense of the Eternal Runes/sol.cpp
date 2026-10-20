#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int find_ans(int tar, unordered_map<int, int>& mp) {
    auto it = mp.find(tar);

    if (tar == 1) {
        return 0;
    }

    if (it != mp.end()) {
        return it->second;
    }

    int mn = tar;

    if (tar % 2 == 0) {
        mn = min(find_ans((int)tar / 2, mp) + 1, mn);
    }
    if (tar % 3 == 0) {
        mn = min(find_ans((int)tar / 3, mp) + 1, mn);
    }
    mn = min(find_ans(tar - 1, mp) + 1, mn);

    mp[tar] = mn;
    return mn;
}

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int imp;
        cin >> imp;
        cout << find_ans(imp, mp) << '\n';
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
