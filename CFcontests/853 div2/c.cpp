#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> f(n + m), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;

        f[a[i]] += m + 1;
    }

    for (int i = 0; i < m; i++)
    {
        int p, v;
        cin >> p >> v;
        p--;
        v--;

        f[a[p]] -= m - i;
        a[p] = v;
        f[a[p]] += m - i;
    }

    long long ans = 1ll * m * (m + 1) * n;
    for (int i = 0; i < n + m; i++)
    {
        ans -= 1ll * f[i] * (f[i] - 1) / 2;
    }

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