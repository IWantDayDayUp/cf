#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int len = s.size();
    s = ' ' + s;

    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    // dp[i][j][k]: 从[1, 1]到[i, j]匹配到第k位的最大值
    vector<vector<vector<int>>> dp(n + 5, vector<vector<int>>(m + 5, vector<int>(s.size() + 5, -1)));
    // dp[1][1][0] = 0;
    vector<vector<int>> ans(n + 5, vector<int>(m + 5, -1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= len; k++)
            {
                if (grid[i][j] != s[k])
                {
                    continue;
                }

                if (k == 1)
                {
                    dp[i][j][k] = max(0, max(ans[i - 1][j], ans[i][j - 1]));
                } else {
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i-1][j][k-1], dp[i][j-1][k-1]));
                }

                if (k == len)
                {
                    dp[i][j][k] += 1;
                }
            }

            ans[i][j] = max(dp[i][j][len], max(ans[i - 1][j], ans[i][j - 1]));
        }
    }

    cout << ans[n][m] << endl;

    return 0;
}