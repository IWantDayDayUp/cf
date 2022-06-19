#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    if ((n + m) % 2 == 0)
    {
        cout << "NO" << endl;
        return ;
    }

    vector<vector<int>> low(n, vector<int>(m, 0)), high(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                low[i][j] = grid[i][j];
                high[i][j] = grid[i][j];
            } else if (i == 0)
            {
                low[i][j] = low[i][j - 1] + grid[i][j];
                high[i][j] = high[i][j - 1] + grid[i][j];
            } else if (j == 0)
            {
                low[i][j] = low[i - 1][j] + grid[i][j];
                high[i][j] = high[i - 1][j] + grid[i][j];
            } else {
                low[i][j] = min(low[i - 1][j], low[i][j - 1]) + grid[i][j];
                high[i][j] = max(high[i - 1][j], high[i][j - 1]) + grid[i][j];
            }
        }
    }

    if (low[n - 1][m - 1] > 0 || high[n - 1][m - 1] < 0)
    {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}