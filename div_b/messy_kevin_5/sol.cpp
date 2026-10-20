#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
0 - 0111111
1 - 0000110
2 - 1011011
3 - 1001111
4 - 1100110
5 - 1101101
6 - 1111101
7 - 0000111
8 - 1111111
9 - 1101111
*/

void solve() {
    unordered_map<string, int> mp;
    mp["0111111"] = 0;
    mp["0000110"] = 1;
    mp["1011011"] = 2;
    mp["1001111"] = 3;
    mp["1100110"] = 4;
    mp["1101101"] = 5;
    mp["1111101"] = 6;
    mp["0000111"] = 7;
    mp["1111111"] = 8;
    mp["1101111"] = 9;

    bitset<7> d1;
    bitset<7> d2;
    cin >> d1;
    cin >> d2;

    d1 |= d2;

    string d1_s = d1.to_string();

    auto itr = mp.find(d1_s);
    if (itr != mp.end()) {
        cout << itr->second << "\n";

    } else {
        cout << -1 << "\n";
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
