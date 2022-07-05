#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> ans(2 * n + 1, vector<int>(2 * n + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i - j >= 0)
            {
                ans[i][n + j] = i - j;
                ans[i][n - j] = i - j;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i - j >= 0)
            {
                ans[2 * n - i][n + j] = i - j;
                ans[2 * n - i][n - j] = i - j;
            }
        }
    }

    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            // cout << ans[i][j] << " \n"[j == 2 * n];
            // cout << (ans[i][j] == -1 ? ' ' : ans[i][j]) << " \n"[j == 2 * n];
            if (ans[i][j] == -1)
            {
                if (j > n)
                {
                    break;
                } else {
                    cout << ' ' << ' ';
                }
            } else {
                if (ans[i][j] == 0 && j >= n)
                {
                    cout << ans[i][j];
                } else {
                    cout << ans[i][j] << ' ';
                }
            }
        }
        cout << endl;
    }

    return 0;
}