#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    auto check = [&](int x, int y)
    {
        return x >= 0 and x < n and y >= 0 and y < n;
    };

    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        grid[i][i] = cur;
        int cnt = cur - 1;

        int x = i, y = i;
        while (cnt > 0)
        {
            if (check(x, y - 1) && grid[x][y - 1] == 0)
            {
                grid[x][y - 1] = cur;
                y -= 1;
            } else {
                grid[x + 1][y] = cur;
                x += 1;
            }
            cnt -= 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << grid[i][j] << " \n"[j == i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    slove();

    return 0;
}