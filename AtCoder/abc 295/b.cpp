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

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#' || grid[i][j] == '.')
            {
                continue;
            }

            int p = grid[i][j] - '0';
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < m; b++)
                {
                    if (abs(a - i) + abs(b - j) <= p)
                    {
                        vis[a][b] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j]) 
            {
                grid[i][j] = '.';
            }

            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}