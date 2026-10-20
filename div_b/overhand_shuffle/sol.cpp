#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,x,k;
    cin >> n >> x >> k;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    if (n == 1){
        cout << a[0] << '\n';
        return;
    }


    x %= (n-1);
    int rem = k - x;
    if (rem < 0){
        rem = (n - 1) + rem;
    };

    if (k == 0){
        cout << a[0] << '\n';
    }

    else if (rem == 0){
        cout << a[n-1] << '\n';
    }
    else{

        cout << a[rem] << '\n';
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
