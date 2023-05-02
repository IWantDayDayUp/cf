#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < m; j += 2)
        {
            int cur = (grid[i][j] + grid[i + 1][j] + grid[i][j + 1] + grid[i + 1][j + 1]) / 4;
            cout << cur << " \n"[j == m - 1];
        }
        cout << endl;
    }

    return 0;
}