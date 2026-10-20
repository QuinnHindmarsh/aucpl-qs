#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int fx, fy;
    cin >> fx >> fy;
    int n;
    cin >> n;

    int dist = abs(fx) + abs(fy);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (abs(x - fx) + abs(y - fy) <= dist) {
            cout << "Oh no! The zombies ate your brains!" << '\n';
            return;
        }
    }
    cout << "Yes! We did it!" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
