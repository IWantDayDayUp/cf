#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    bool two = false, one = false, dig = false;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                cnt += 1;
                continue;
            }

            if ((i - 1 >= 0 && grid[i - 1][j] == '0') || (i + 1 < n && grid[i + 1][j] == '0') || (j - 1 >= 0 && grid[i][j - 1] == '0') || (j + 1 < m && grid[i][j + 1] == '0'))
            {
                two = true;
            }

            if ((i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == '0') || (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] == '0'))
            {
                dig = true;
            }
            if ((i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == '0') || (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == '0'))
            {
                dig = true;
            }

            one = true;
        }
    }

    // cout << two << ' ' << one << ' ' << cnt << endl;

    if (two)
    {
        cout << cnt << endl;
    } else if (dig){
        cout << cnt - 1 + 1 << endl;
    } else if (one)
    {
        cout << cnt - 2 + 1 << endl;
    } else {
        cout << cnt - 3 + 1 << endl;
    }
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