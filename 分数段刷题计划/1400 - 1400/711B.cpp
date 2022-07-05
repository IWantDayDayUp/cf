#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<long long>> grid(n, vector<long long>(n));
    vector<long long> r(n, 0), c(n, 0);
    long long s1 = 0, s2 = 0;
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            r[i] += grid[i][j];
            c[j] += grid[i][j];

            if (i == j)
            {
                s1 += grid[i][j];
            }
            if (i + j == n - 1)
            {
                s2 += grid[i][j];
            }

            if (grid[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }

    long long mx = *max_element(r.begin(), r.end());
    long long ans = mx - r[x];

    r[x] += ans;
    c[y] += ans;
    if (x == y) s1 += ans;
    if (x + y == n - 1) s2 += ans;

    bool ok = true;
    if (s1 != s2)
    {
        ok = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (r[i] != s1) ok = false;
        if (c[i] != s1) ok = false;
    }

    if (n == 1)
    {
        cout << (grid[0][0] == 0 ? 1 : 0) << endl;
        return 0;
    }

    if (ok && ans > 0)
    {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}