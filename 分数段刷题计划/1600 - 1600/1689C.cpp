#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

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

    // the maximum number of vertices we can save in the subtree of vertex i 
    // if that vertex is infected and we use operations only in the subtree.
    vector<int> dp(n, 0);
    // 子树节点个数
    vector<int> cnt(n, 0);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        cnt[u] = 1;  // 本身算一个
        int s = 0;
        for (auto & v : adj[u])
        {
            if (v == p) continue;
            dfs(v, u);
            s += dp[v];
            cnt[u] += cnt[v];
        }

        for (auto & v : adj[u])
        {
            if (v == p) continue;
            // save the subtree of one child by deleting it and infect the other, or the other way around
            // 删掉一个子节点, 拯救其他的
            // s - dp[v]: 其他被拯救的
            // cnt[v] - 1: 被删掉的子节点, 它的所有子节点也都会没事
            dp[u] = max(dp[u], s - dp[v] + cnt[v] - 1);
        }
    };

    dfs(0, -1);

    cout << dp[0] << endl;
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