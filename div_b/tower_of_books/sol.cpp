#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> books;

    for (int i = 0; i < n; i++) {
        int new_book;
        cin >> new_book;

        while (!books.empty() && books.back() < new_book) {
            books.pop_back();
        }

        books.push_back(new_book);
    }

    cout << books.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
