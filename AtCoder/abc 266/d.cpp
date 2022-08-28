#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<long long>> a(5, vector<long long>(1e5 + 5));

    for (int i = 1; i <= n; i++)
    {
        int t, x;
        cin >> t >> x;

        cin >> a[x][t];
    }

    vector<vector<long long>> dp(5, vector<long long>(1e5 + 5, -1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= 1e5; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + a[0][i];
        dp[1][i] = max(dp[1][i - 1], max(dp[0][i - 1], dp[2][i - 1])) + a[1][i];
        dp[2][i] = max(dp[2][i - 1], max(dp[1][i - 1], dp[3][i - 1])) + a[2][i];
        dp[3][i] = max(dp[3][i - 1], max(dp[2][i - 1], dp[4][i - 1])) + a[3][i];
        dp[4][i] = max(dp[4][i - 1], dp[3][i - 1]) + a[4][i];
    }

    long long ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans = max(ans, dp[i][1e5]);
    }

    cout << ans << endl;
    
    return 0;
}