#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int intersection_length(const unordered_set<string>& a, const unordered_set<string>& b) {
    const auto& small = (a.size() < b.size()) ? a : b;
    const auto& big = (a.size() < b.size()) ? b : a;
    int intersection = 0;

    for (const string& e : small) {
        if (big.contains(e)) {
            intersection++;
        }
    }
    return intersection;
}

void solve() {
    int n;
    cin >> n;

    unordered_set<string> pref;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        pref.insert(x);
    }

    unordered_map<string, unordered_set<string>> mp;

    int p;
    cin >> p;

    for (int i = 0; i < p; i++) {
        string c, d;
        cin >> c >> d;
        mp[c].insert(d);
    }

    int mx = 0;
    string mx_name = "none";

    for (const auto& [key, val] : mp) {
        int intersection_size = intersection_length(val, pref);

        if (intersection_size > mx ||
            (intersection_size >= 1 && mx == intersection_size && key < mx_name)) {
            mx = intersection_size;
            mx_name = key;
        }
    }

    cout << mx_name << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
