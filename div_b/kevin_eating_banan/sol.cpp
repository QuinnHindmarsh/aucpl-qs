#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, h, k;
    cin >> n >> h >> k;

    priority_queue<ll> pq;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    for (ll i = 0; i < h; i++) {
        ll tp = pq.top();
        if (tp == 0) break;
        pq.pop();

        tp = max(tp - k, (ll)0);
        pq.push(tp);
    }

    cout << pq.top() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
