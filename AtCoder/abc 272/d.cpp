#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> d;
    for (int i = -n; i < n; i++)
    {
        for (int j = -n; j < n; j++)
        {
            if (i * i + j * j == m)
            {
                d.emplace_back(make_pair(i, j));
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    dp[1][1] = 0;

    queue<pair<int, int>> q;
    q.emplace(make_pair(1, 1));

    int step = 0;

    while (!q.empty())
    {
        step += 1;

        int cnt = q.size();
        for (int _ = 0; _ < cnt; _++)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (auto & p : d)
            {
                int nx = x + p.first, ny = y + p.second;
                if (nx < 1 || nx > n || ny < 1 || ny > n)
                {
                    continue;
                }
                if (dp[nx][ny] > step)
                {
                    dp[nx][ny] = step;
                    q.emplace(make_pair(nx, ny));
                }
            }
            
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == 1e9)
            {
                dp[i][j] = -1;
            }
            cout << dp[i][j] << " \n"[j == n];
        }
    }

    return 0;
}