#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n + 2);
    grid[0] = string(m + 2, '.');
    grid[n + 1] = string(m + 2, '.');

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        s = "." + s + ".";

        grid[i] = s;
    }

    // for (int i = 0; i < n + 2; i++)
    // {
    //     cout << grid[i] << endl;
    // }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '*')
            {
                if (grid[i][j + 1] == '*' && grid[i + 1][j + 1] == '*' && grid[i + 1][j] != '*')
                {
                    int cnt = 0;
                    for (int nx = i - 1; nx <= i + 2; nx++)
                    {
                        for (int ny = j - 1; ny <= j + 2; ny++)
                        {
                            if (grid[nx][ny] == '*')
                            {
                                cnt += 1;
                            }
                        }
                    }
                    if (grid[i + 2][j - 1] == '*')
                    {
                        cnt -= 1;
                    }

                    if (cnt != 3)
                    {
                        cout << "NO" << endl;
                        // cout << 1 << ' '  << i << ' ' << j << endl;
                        return;
                    }

                    grid[i][j] = grid[i][j + 1] = grid[i + 1][j + 1] = '.';

                } else if (grid[i + 1][j] == '*' && grid[i + 1][j + 1] == '*' && grid[i][j + 1] != '*')
                {
                    int cnt = 0;
                    for (int nx = i - 1; nx <= i + 2; nx++)
                    {
                        for (int ny = j - 1; ny <= j + 2; ny++)
                        {
                            if (grid[nx][ny] == '*')
                            {
                                cnt += 1;
                            }
                        }
                    }
                    if (grid[i - 1][j + 2] == '*')
                    {
                        cnt -= 1;
                    }

                    if (cnt != 3)
                    {
                        cout << "NO" << endl;
                        // cout << 2 << ' '  << i << ' ' << j << endl;
                        return;
                    }

                    grid[i][j] = grid[i + 1][j] = grid[i + 1][j + 1] = '.';

                } else if (grid[i + 1][j] == '*' && grid[i][j + 1] == '*' && grid[i + 1][j + 1] != '*') 
                {
                    int cnt = 0;
                    for (int nx = i - 1; nx <= i + 2; nx++)
                    {
                        for (int ny = j - 1; ny <= j + 2; ny++)
                        {
                            if (grid[nx][ny] == '*')
                            {
                                cnt += 1;
                            }
                        }
                    }
                    if (grid[i + 2][j + 2] == '*')
                    {
                        cnt -= 1;
                    }

                    if (cnt != 3)
                    {
                        cout << "NO" << endl;
                        // cout << 3 << ' '  << i << ' ' << j << endl;
                        return;
                    }

                    grid[i][j] = grid[i + 1][j] = grid[i][j + 1] = '.';

                } else if (grid[i + 1][j] == '*' && grid[i + 1][j - 1] == '*' && grid[i][j + 1] != '*' && grid[i + 1][j + 1] != '*')
                {
                    int cnt = 0;
                    for (int nx = i - 1; nx <= i + 2; nx++)
                    {
                        for (int ny = j - 2; ny <= j + 1; ny++)
                        {
                            if (grid[nx][ny] == '*')
                            {
                                cnt += 1;
                            }
                        }
                    }
                    // if (grid[i + 2][j - 1] == '*')
                    // {
                    //     cnt -= 1;
                    // }

                    if (cnt != 3)
                    {
                        cout << "NO" << endl;
                        // cout << 4 << ' '  << i << ' ' << j << endl;
                        return;
                    }

                    grid[i][j] = grid[i + 1][j] = grid[i + 1][j - 1] = '.';

                } else {
                    cout << "NO" << endl;
                    // cout << 5 << ' ' << i << ' ' << j << endl;
                    return;
                }
            }
        }
    }

    // for (int i = 0; i < n + 2; i++)
    // {
    //     cout << grid[i] << endl;
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '*')
            {
                cout << "NO" << endl;
                // cout << 0 << ' ' << i << ' ' << j << endl;
                return ;
            }
        }
    }

    cout << "YES" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}