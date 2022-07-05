#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    int p = 0, q = 0;
    for (int i = 1; i <= k; i++)
    {
        grid[p + 1][q + 1] = 1;
        p += 1;
        q = (q + 1) % n;

        if (p == n)
        {
            p = 0;
            q = (q + 1) % n;
        }

    }

    cout << (k % n == 0 ? 0 : 2) << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
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