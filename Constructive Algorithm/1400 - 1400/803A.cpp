#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;

    if (n * n < k)
    {
        cout << -1 << endl;
        return ;
    }

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1) continue;
            if (i == j)
            {
                grid[i][j] = 1;
                k -= 1;
            } else if (k > 1)
            {
                grid[i][j] = 1;
                grid[j][i] = 1;
                k -= 2;
            }
        }
        if (k == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    slove();

    return 0;
}