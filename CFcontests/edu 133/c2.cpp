#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<vector<int>> grid(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> suf1(2, vector<int>(n + 1, -1e9)), suf2(2, vector<int>(n + 1, -1e9));
    for (int i = 0; i < 2; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            suf1[i][j] = max(suf1[i][j + 1], grid[i][j] + j);
            suf2[i][j] = max(suf2[i][j + 1], grid[i][j] - j);
        }
    }

    int ans = int(1e9) + int(1e8);
    int cur = 0;

    // 更方便的实现蛇形操作
    vector<vector<bool>> vis(2, vector<bool>(n, false));
    vis[0][0] = true;

    int i = 0, j = 0;
    while (1)
    {
        if (!vis[i ^ 1][j])
        {
            // 从 `j` 列走到 `n - 1` 列(0-based)的最短时间
            // 1. (全部解锁)从当前 j 列直接去 n - 1 列, 需要花费: cur + (n - 1) - j
            // 2. (部分解锁)从当前 j 列先去 y(j <= y <= n - 1) 列, 解锁 y 列, 然后去 n - 1 列, 需要花费: (grid[i][y] + 1) + (n - 1) - y
            int temp = max(cur + n - 1 - j, n - 1 + 1 + suf2[i][j + 1]);

            // 从 n - 1 列走回 j 列的最短时间
            // 1. (全部解锁)畅通无阻, 需要花费: temp + 1 + (n - 1) - j
            // 2. (部分解锁)中转站 y 列, 需要花费: (grid[i][j] + 1) + (y - j)
            ans = min(ans, max(temp + n - 1 - j + 1, suf1[i ^ 1][j] - j + 1));

            // 转换到另外一行
            i ^= 1;
        } else {
            j += 1;
        }

        if (j >= n)
        {
            break;
        }

        vis[i][j] = true;

        // 1. cur + 1: 从前一列的格子运动过来, 固定花费1秒
        // 2. grid[i][j] + 1: 解锁该格子的最小时间 
        cur = max(cur + 1, grid[i][j] + 1);
    }

    cout << min(ans, cur) << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}