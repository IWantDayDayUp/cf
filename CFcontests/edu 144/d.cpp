#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    constexpr long long inf = 1e18;

    vector<array<long long, 3>> dp(k + 1, array<long long, 3>{-inf, -inf, -inf});
    dp[0] = {};

    for (int i = 0; i < n; i++)
    {
        vector<array<long long, 3>> g(k + 1, array<long long, 3>{-inf, -inf, -inf});
        for (int j = 0; j <= k; j++)
        {
            for (int t = 0; t < 3; t++)
            {
                g[j][t] = max(g[j][t], dp[j][t] + (t == 1 ? a[i] - x : 0));
                if (j < k)
                {
                    g[j + 1][t] = max(g[j + 1][t], dp[j][t] + (t == 1 ? a[i] + x : 0));
                }
            }
        }
        for (int j = 0; j <= k; j++)
        {
            for (int t = 1; t < 3; t++)
            {
                g[j][t] = max(g[j][t], g[j][t - 1]);
            }
        }

        dp = g;
    }

    auto ans = dp[k][2];
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