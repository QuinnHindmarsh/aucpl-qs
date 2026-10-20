#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    int counter = 100;

    // more optimal with ll

    set<int> removed = {};

    while (a.size() - removed.size() > 1){
        for (int i = 0; i < (int) a.size(); i++){
            if (removed.find(i) != removed.end()){
                continue;

            };

            counter -= a[i];

            if (counter  <= 0){
                counter = 100;
                removed.insert(i);

            };
        };

    };

    for (int i = 0; i < (int) a.size(); i++){
        if (removed.find(i) == removed.end()){
            cout << a[i] << '\n';
        };
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
