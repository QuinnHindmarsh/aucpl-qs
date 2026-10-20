#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    stack<char> left;
    stack<char> right;

    for (int i = 0; i < n; i++) {
        string code;
        cin >> code;

        if (code == "ADD") {
            string text;
            cin >> text;
            vector<char> char_vector(text.begin(), text.end());

            for (char ch : char_vector) {
                left.push(ch);
            }

        } else if (code == "DEL") {
            int k;
            cin >> k;

            while (!left.empty() && k > 0) {
                left.pop();
                k--;
            }

        } else if (code == "LEFT") {
            int k;
            cin >> k;

            while (!left.empty() && k > 0) {
                char tp = left.top();
                left.pop();
                right.push(tp);
                k--;
            }
        } else if (code == "RIGHT") {
            int k;
            cin >> k;

            while (!right.empty() && k > 0) {
                char tp = right.top();
                right.pop();
                left.push(tp);
                k--;
            }
        }
    }

    string ls;
    string lr;

    while (!left.empty()) {
        ls.push_back(left.top());
        left.pop();
    }

    while (!right.empty()) {
        lr.push_back(right.top());
        right.pop();
    }

    string final;
    reverse(ls.begin(), ls.end());
    final = ls;
    final.append(lr);

    cout << final << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
