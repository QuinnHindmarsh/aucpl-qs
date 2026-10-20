#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    int main_num = 0;
    stack<int> s;

    for (ll& x : a) cin >> x;

    for (int num : a) {
        if (num == main_num + 1) {
            ++main_num;
            while (!s.empty() && s.top() == main_num + 1) {
                ++main_num;
                s.pop();
            }
        } else {
            s.push(num);
        }
    }

    if (main_num == n) {
        cout << "Tung Tung Tung" << "\n";
    } else {
        cout << "Mamma Mia!" << "\n";
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
