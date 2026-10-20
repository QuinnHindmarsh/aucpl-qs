#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;


    if (n == 1){
        cout << 1 << "\n";
        return;
    }else if (n < 4){
        cout << "Impossible" << "\n";
        return ;
    }

    vector<int> even(int (n/2));
    vector<int> odd(int ((n+1)/2));
    
    for (int i = 1; (int) i /2 < (int) odd.size(); i+=2){
        odd[(int) i/2] = i;
    };

    for (int i = 2; (i/2) -1 < (int) even.size(); i+=2){
        even[(int) (i/2) -1] = i;

    };



    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for (int num : even){
        cout << num << ' ';
    };

    for (int num : odd){
        cout << num << ' ';
    };
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;          // uncomment for multi-testcase problems
    while (t--) solve();

    return 0;
}
