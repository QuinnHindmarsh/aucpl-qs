#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    queue<string> q;
    string ans = "";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        if (!temp.empty() && temp.back() == '\r') temp.pop_back();

        q.push(temp);
    }

    while (!q.empty()) {
        string s = q.front();
        q.pop();

        if (s.length() > 80) {
            string temp = s.substr(0, 80);
            int i = 80;
            // while (i < (int)s.length() && s[i] == '.') {
            //     temp += s[i];
            //     i++;
            // }
            if (i < (int)s.length()) {
                q.push(s.substr(i));
            }
            ans += temp;
        } else {
            ans += s;
        }
        ans += '\n';
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
