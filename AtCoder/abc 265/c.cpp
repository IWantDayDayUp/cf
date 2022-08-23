#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[0][0] = true;

    int i = 0, j = 0;

    auto check = [&](int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    while (true)
    {
        if (grid[i][j] == 'U')
        {
            i -= 1;
            j += 0;
            if (!check(i, j))
            {
                cout << i + 1 + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        } else if (grid[i][j] == 'D')
        {
            i += 1;
            j += 0;
            if (!check(i, j))
            {
                cout << i - 1 + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        } else if (grid[i][j] == 'L')
        {
            i += 0;
            j -= 1;
            if (!check(i, j))
            {
                cout << i + 1 << ' ' << j + 1 + 1 << endl;
                return 0;
            }
        } else {
            i += 0;
            j += 1;
            if (!check(i, j))
            {
                cout << i + 1 << ' ' << j - 1 + 1 << endl;
                return 0;
            }
        }

        if (vis[i][j] == true)
        {
            cout << -1 << endl;
            return 0;
        }

        vis[i][j] = true;
    }

    return 0;
}