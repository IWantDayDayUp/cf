#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '@')
            {
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                vis[i][j] = true;

                queue<pair<int, int>> q;
                q.push({i, j});

                int dx[4] = {-1, 1, 0, 0};
                int dy[4] = {0, 0, 1, -1};

                while (!q.empty())
                {
                    auto cur = q.front();
                    int x = cur.first, y = cur.second;
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny])
                        {
                            continue;
                        }

                        if (a[nx][ny] == '#')
                        {
                            continue;
                        }

                        q.push({nx, ny});
                        vis[nx][ny] = true;

                        ans += a[nx][ny] == '!';
                    }
                }

            }
        }
    }

    cout << ans << endl;

    return 0;
}