#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > q)
        {
            if (cnt >= k)
            {
                ans += 1ll * (cnt - k + 1) * (cnt - k + 2) / 2;
            }
            cnt = 0;
        } else {
            cnt += 1;
        }
    }

    if (cnt >= k)
    {
        ans += 1ll * (cnt - k + 1) * (cnt - k + 2) / 2;
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