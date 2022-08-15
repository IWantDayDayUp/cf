#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> w(n), v(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 2e9));
    dp[0][0] = 0;

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (long long j = sum; j >= 0; j--)
        {
            if (j < v[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }

            if (dp[i][j] <= m)
            {
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}