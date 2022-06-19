#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove()
{
    int n, m;
    cin >> n >> m;

    int max_i = 0, max_j = 0;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] > grid[max_i][max_j])
            {
                max_i = i, max_j = j;
            }
        }
    }

    int h = max(max_i + 1, n - max_i);
    int w = max(max_j + 1, m - max_j);

    cout << h * w << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }

    return 0;
}