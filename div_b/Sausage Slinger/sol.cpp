#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll bin_search(ll tar, vector<ll>& arr, int l, int r) {
    int mid = l + (r - l) / 2;

    if (r == l) {
        return arr[l];
    }

    if (arr[mid] < tar) {
        return bin_search(tar, arr, mid + 1, r);
    } else if (arr[mid] > tar) {
        return bin_search(tar, arr, l, mid);
    }
    return arr[mid];
}

void solve() {
    int n;
    cin >> n;

    vector<ll> pos(n);
    for (ll& x : pos) cin >> x;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        ll hot_dog_pos;
        cin >> hot_dog_pos;

        ll res = bin_search(hot_dog_pos, pos, 0, n - 1);

        if (res < hot_dog_pos) {
            cout << -1 << endl;

        } else {
            cout << res << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;  // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
