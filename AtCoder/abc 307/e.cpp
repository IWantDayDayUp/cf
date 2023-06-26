#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(2, vector<long long>(n + 1));
    dp[1][1] = m;

    long long mod = 998244353;

    for (int i = 0; i < n; i++)
    {
        dp[0][i + 1] += dp[0][i] * (m - 2);
        dp[1][i + 1] += dp[0][i];
        dp[0][i + 1] += dp[1][i] * (m - 1);

        dp[0][i + 1] %= mod;
        dp[1][i + 1] %= mod;
    }

    cout << dp[0][n] << endl;

    return 0;
}