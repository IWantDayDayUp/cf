#include <bits/stdc++.h>

using i64 = long long;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<bool> cyc(n);
    std::vector<int> parent(n, -1), vis(n, -1);
    
    int cur = 0;
    std::function<void(int)> dfs = [&](int x) {
        vis[x] = cur++;
        for (auto y : adj[x]) {
            if (y == parent[x]) {
                continue;
            }
            if (vis[y] == -1) {
                parent[y] = x;
                dfs(y);
            } else if (vis[x] > vis[y]) {
                for (int i = x; i != y; i = parent[i]) {
                    cyc[i] = true;
                }
                cyc[y] = true;
            }
        }
    };
    dfs(0);
    
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            if (!cyc[i] || !cyc[j]) {
                dsu.merge(i, j);
            }
        }
    }
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        std::cout << (dsu.same(u, v) ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
