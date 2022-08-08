#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, l, r;
    cin >> n >> l >> r;

    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<long long>> dp(3, vector<long long>(n + 1, 1e18));
    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + l;
        dp[1][i] = min(dp[1][i - 1] + a[i], dp[0][i]);
        dp[2][i] = min(dp[2][i - 1] + r, dp[1][i]);
    }

    cout << dp[2][n] << endl;

    return 0;
}