#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
find proper divisors?

get_proper_divisors(int n)
- itr from 1 -> sqrt(n) and find the reciprical



*/

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Jamie" << endl;

    }
    else {
        cout << "Marcus" << endl;
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
