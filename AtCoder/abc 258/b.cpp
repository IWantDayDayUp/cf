#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            grid[i][j] = c - '0';
        }
    }

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                long long temp = 0;

                int nx = i;
                int ny = j;

                for (int m = 0; m < n; m++)
                {
                    temp = temp * 10 + grid[nx][ny];

                    nx += dx[k];
                    ny += dy[k];

                    nx = (nx + n) % n;
                    ny = (ny + n) % n;

                    // nx %= n;
                    // nx += n;
                    // nx %= n;

                    // ny %= n;
                    // ny += n;
                    // ny %= n;
                }

                // cout << temp << endl;
                ans = max(ans, temp);
            }
        }
    }

    cout << ans << endl;

    return 0;
}