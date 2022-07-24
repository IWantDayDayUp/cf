#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> x(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    } 

    map<int, long long> mp;
    for (int i = 0; i < m; i++)
    {
        int c, y;
        cin >> c >> y;

        mp[c] = y;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    dp[1][1] = x[1] + mp[1];

    for (int i = 2; i <= n; i++)
    {
        long long cur = 0;
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + x[i] + mp[j];
            cur = max(cur, dp[i - 1][j - 1]);
        }

        dp[i][0] = cur;
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}