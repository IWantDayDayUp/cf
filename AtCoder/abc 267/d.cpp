#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int j = 1; j <= m; j++)
    {
        long long pre = dp[j - 1][j - 1];
        for (int i = j; i <= n; i++)
        {
            dp[i][j] = max(dp[i][j], a[i] * j + pre);

            pre = max(pre, dp[i][j - 1]);
        }
    }

    long long ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i][m]);
    }

    cout << ans << endl;

    return 0;
}