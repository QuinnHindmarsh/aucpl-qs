#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    int r = 0;
    int l = 0;
    int mx = 1;

    while (l < n-1){
        r = l +1;
        while (r < n){
            if (a[r-1] <= a[r]){
                break;
            }
            r++;
        }
        mx = max(mx, r - l );
        l = r;

    };

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
