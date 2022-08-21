#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 1)
    {
        cout << 0 << endl;
        return ;
    }

    cout << n - 1 + m - 1 + min(n, m) << endl;
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