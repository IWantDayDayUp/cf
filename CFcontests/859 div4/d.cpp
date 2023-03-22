#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        a[i] += a[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        long long k;
        cin >> l >> r >> k;
        l--;
        r--;

        long long cur = a[n];
        cur += 1ll * (r - l + 1) * k;
        cur -= (a[r + 1] - a[l]);

        cout << (cur & 1 ? "YES" : "NO") << endl;
    }
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