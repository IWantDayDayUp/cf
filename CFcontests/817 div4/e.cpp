#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<long long>> grid(1000 + 1, vector<long long>(1000 + 1));
    for (int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;

        grid[h][w] += h * w;
    }

    vector<vector<long long>> pre(1000 + 5, vector<long long>(1000 + 5, 0));
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + grid[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;

        long long ans = pre[h2][w2] - pre[h1 + 1][w2] - pre[h2][w1 + 1] + pre[h1 + 1][w1 + 1] ;

        cout << ans << endl;
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