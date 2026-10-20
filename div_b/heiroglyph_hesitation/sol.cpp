#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool can_do(vector<ll>& arr, const ll& k, const ll& x) {
    ll breaks_used = 0;
    ll cur_sum = 0;

    for (ll num : arr) {
        if (num > x) return false;
        if (cur_sum + num > x) {
            breaks_used++;
            cur_sum = 0;
        }
        cur_sum += num;
    }
    return breaks_used <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;

    ll l = *max_element(a.begin(), a.end());
    ll r = pow(10, 9) + 1;  //+1 to account for percision errors

    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (can_do(a, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
