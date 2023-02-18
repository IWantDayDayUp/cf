#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, n - 1);

    while (!q.empty())
    {
        auto [d, x, y] = q.front();

        q.pop();

        if (dp[x][y] != -1)
        {
            continue;
        }

        dp[x][y] = d;
        for (auto & a : adj[x])
        {
            for (auto & b : adj[y])
            {
                if (c[a] != c[b])
                {
                    q.emplace(d + 1, a, b);
                }
            }
        }
    }

    cout << dp[n - 1][0] << endl;
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