#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> w(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    for (int j = w[0]; j <= m; j++)
    {
        dp[0][j] = v[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j < w[i])
            {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n - 1][m] << endl;

    return 0;
}