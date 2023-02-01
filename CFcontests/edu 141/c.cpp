#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto b = a;
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n && b[i] <= m; i++)
    {
        m -= b[i];
        ans += 1;
    }

    if (ans != 0 && ans != n && m + b[ans - 1] >= a[ans])
    {
        ans += 1;
    }

    cout << n + 1 - ans << endl;
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