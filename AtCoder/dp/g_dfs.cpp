#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        vis[v] = true;
        adj[u].emplace_back(v);
    }

    vector<int> dp(n, -1);

    function<int(int)> dfs = [&](int u)
    {
        if (dp[u] != -1)
        {
            return dp[u];
        }

        dp[u] = 0;
        for (auto & v : adj[u])
        {
            dp[u] = max(dp[u], dfs(v) + 1);
        }
        return dp[u];
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans = max(ans, dfs(i));
        }
    }

    cout << ans << endl;

    return 0;
}