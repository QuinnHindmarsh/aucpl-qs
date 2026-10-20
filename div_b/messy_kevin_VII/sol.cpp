#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s, b;
    cin >> s >> b;

    vector<pair<int, int>> tasks(s);
    for (auto& [d, p] : tasks) cin >> d >> p;

    vector<int> breaks(b);
    for (int& x : breaks) cin >> x;

    ranges::sort(breaks, ranges::greater{});
    ranges::sort(tasks, [](const auto& x, const auto& y) {
        return tie(x.second, x.first) > tie(y.second, y.first);
    });

    const int DAY = 720;
    int study = 0, rest = 0;

    for (auto [dur, _] : tasks) {
        if (study > 0 && !breaks.empty()) {
            if (study + rest + breaks.back() > DAY) break;
            rest += breaks.back();
            breaks.pop_back();
        }
        if (study + rest + dur > DAY) break;
        study += dur;
    }

    cout << study << ' ' << rest << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
