#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return ;
    }

    int ans = 0;
    function<void(int, int)> dfs = [&](int l, int r)
    {
        if (l == r) return;

        int mid = l + r >> 1;

        if (a[l] > a[r]) ans += 1;

        int mn1 = 1e9, mx1 = 0, mn2 = 1e9, mx2 = 0;
        for (int i = l; i <= mid; i++)
        {
            mn1 = min(mn1, a[i]);
            mx1 = max(mx1, a[i]);
        }
        for (int i = mid + 1; i <= r; i++)
        {
            mn2 = min(mn2, a[i]);
            mx2 = max(mx2, a[i]);
        }

        if (a[l] > a[r])
        {
            if (mn1 < mx2)
            {
                ans = 1e9;
                return;
            }
        } else {
            if (mx1 > mn2)
            {
                ans = 1e9;
                return;
            }
        }

        dfs(l, mid);
        dfs(mid + 1, r);
    };

    dfs(0, n - 1);

    if (ans >= 1e9)
    {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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