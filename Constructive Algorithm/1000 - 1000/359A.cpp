#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<int> row(n), col(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                row[i] += 1;
                col[j] += 1;
            }
        }
    }

    if (row[0] || row[n - 1] || col[0] || col[m - 1])
    {
        cout << 2 << endl;
    } else {
        cout << 4 << endl;
    }
    
    return 0;
}