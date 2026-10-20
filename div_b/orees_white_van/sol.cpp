#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    int m; 
    cin >> m;
    vector<pair<int,int>> b(m);
    for (auto &[u,v] : b) cin >> u >> v;

    for (int i = 1; i < (int) a.size(); i++){
        a[i] += a[i-1];
    };

    for (auto [u,v] : b){
        int sum ; 
        if (u == 0){
            sum = a[v];
        }else {
            sum = a[v] - a[u -1];
        };

        if (sum == 0){
            sum += 100; 
        } else if (sum > 0){
            sum += 10;
        } else{
            sum -= 10;
        }

        cout << sum << "\n";
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


/*
-10 if negative
+100 if 0
+10 if possitive
*/
