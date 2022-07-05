#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<vector<long long>> dp(2, vector<long long>(n, 0));

    function<void(int, int)> dfs = [&](int u, int p)
    {
        dp[0][u] = dp[1][u] = 0;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            dfs(v, u);
            dp[0][u] += max(abs(l[u] - r[v]) + dp[1][v], dp[0][v] + abs(l[u] - l[v]));
            dp[1][u] += max(abs(r[u] - r[v]) + dp[1][v], dp[0][v] + abs(r[u] - l[v]));
        }
    };

    dfs(0, -1);

    cout << max(dp[0][0], dp[1][0]) << endl;
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