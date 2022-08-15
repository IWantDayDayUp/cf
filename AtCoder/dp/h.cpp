#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    dp[0][0] = 1;

    long long mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0 || grid[i][j] == '#')
            {
                continue;
            } else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] % mod;
            } else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] % mod;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}