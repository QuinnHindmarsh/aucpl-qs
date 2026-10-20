#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n {3};

    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    int x = a[0]; 
    int y = a[1]; 
    int k = a[2]; 

    int total = x + y;
    
    if (total > k){
    cout << "No" << "\n";

    } else {
        int diff = total -k; 
        if (diff % 2 == 0){
            cout << "Yes" << "\n";

        }
        else{
            cout << "No" << "\n";
        }
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
