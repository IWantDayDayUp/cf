#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> siz(n);
    auto dfs = [&](auto self, int u, int p) -> void {
        for (auto & v : adj[u])
        {
            if (v != p)
            {
                self(self, v, u);
                siz[u] += siz[v];
            }
        }
        if (siz[u] == 0)
        {
            siz[u] = 1;
        }
    };
    dfs(dfs, 0, -1);

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;

        cout << 1ll * siz[x] * siz[y] << endl;
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