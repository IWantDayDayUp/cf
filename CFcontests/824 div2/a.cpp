#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = max(0, n - 6) / 3;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}