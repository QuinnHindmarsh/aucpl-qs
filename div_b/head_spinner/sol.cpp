#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (string& x : a) cin >> x;

    int cnt = 0;
    cnt += count(a[0].begin(), a[0].end(), 'a');
    cnt += count(a[0].begin(), a[0].end(), 'e');
    cnt += count(a[0].begin(), a[0].end(), 'i');
    cnt += count(a[0].begin(), a[0].end(), 'o');
    cnt += count(a[0].begin(), a[0].end(), 'u');

    bool first_even = (cnt % 2 == 0);

    for (string s : a) {
        int cnt = 0;
        cnt += count(s.begin(), s.end(), 'a');
        cnt += count(s.begin(), s.end(), 'e');
        cnt += count(s.begin(), s.end(), 'i');
        cnt += count(s.begin(), s.end(), 'o');
        cnt += count(s.begin(), s.end(), 'u');

        if (first_even != (cnt % 2 == 0)) {
            reverse(s.begin(), s.end());
        };

        cout << s << '\n';


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
