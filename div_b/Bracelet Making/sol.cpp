#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        string dir;
        cin >> dir;

        if (type == "INSERT") {
            char ch;
            cin >> ch;
            if (dir == "LEFT") {
                dq.push_front(ch);
            } else {
                dq.push_back(ch);
            }
        } else {
            int times;
            cin >> times;

            times %= dq.size();

            for (int j = 0; j < times; j++) {
                if (dir == "LEFT") {
                    char temp;
                    temp = dq.back();
                    dq.pop_back();
                    dq.push_front(temp);
                } else {
                    char temp;

                    temp = dq.front();

                    dq.pop_front();

                    dq.push_back(temp);
                }
            }
        }
    }

    string ans = "";
    while (!dq.empty()) {
        ans += dq.front();
        dq.pop_front();
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
