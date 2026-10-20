#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for (auto &[x,y] : a) cin >> x >> y;

    double slope;
    double temp_slope; 

    if (n <= 2){
        cout << "YES" << "\n";
        return;
    }
    if (a[0].first == a[1].first){
        for (int i = 2; i < (int) a.size(); i++){
            if (a[i].first != a[i].first){
                cout << "NO" << "\n";
                return; 
            };
        }
        cout << "YES" << "\n"; 
        return; 
    }

    slope = (a[1].second - a[0].second) / (a[1].first - a[0].first );
    
    for (int i = 2; i < (int) a.size(); i++){
        if (a[i].first == a[i-1].first){
            cout << "NO" << "\n";
            return; 
        };
        
        temp_slope = (a[i].second - a[i-1].second) / (a[i].first - a[i-1].first );
        
        if (temp_slope != slope) {
            cout << "NO" << "\n";
            return ;
        };
    };
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
};
