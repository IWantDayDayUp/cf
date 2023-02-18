#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int L = 1, R = 50;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        if (l <= k && k <= r)
        {
            L = max(L, l);
            R = min(R, r);
        }
    }

    cout << (L == R ? "YES" : "NO") << endl;
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