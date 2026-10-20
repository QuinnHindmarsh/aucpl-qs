#include <bits/stdc++.h>
using namespace std;

using ll = long long;



int helper(unordered_map<int, int>& map, int num) {

    int origonal_num = num;
    auto it = map.find(num);
    if (num == 1) {
        return 0;
    }
    else if (it != map.end()) {
        return it-> second;
    }
    else if (num % 2 == 0) {
        num /= 2;
    }
    else {
        num *= 3;
        num += 1;
    }

    map[origonal_num] = helper(map, num) + 1;
    return map[origonal_num];

}

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> moves_to_1;
    int mx_moves = 0;
    int ans = 1;

    for (int i = 2; i <= n; i++) {
        int moves = helper(moves_to_1, i);

        if (moves >= mx_moves) {
            mx_moves = moves;
            ans = i;
        }
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
