#include <bits/stdc++.h>

using i64 = long long;

struct Flow {
    static constexpr i64 INF = 1E18;
    int n;
    struct Edge {
        int to;
        i64 cap;
        Edge(int to, i64 cap) : to(to), cap(cap) {}
    };
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t) {
        h.assign(n, -1);
        queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) {
                int v = e[i].to;
                i64 c = e[i].cap;
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    i64 dfs(int u, int t, i64 f) {
        if (u == t)
            return f;
        i64 r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i];
            int v = e[j].to;
            i64 c = e[j].cap;
            if (c > 0 && h[v] == h[u] + 1) {
                i64 a = dfs(v, t, min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, i64 c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    i64 maxFlow(int s, int t) {
        i64 ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, INF);
        }
        return ans;
    }
};

constexpr i64 inf = 1E18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    Flow flow(n + m + 2);
    int source = n + m, sink = n + m + 1;
    
    vector a(n, vector<int>(m));
    vector<i64> sumr(n), sumc(m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sumr[i] += a[i][j];
            sumc[j] += a[i][j];
        }
    }
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (sumr[i] > 0) {
            ans += sumr[i];
            flow.addEdge(source, i, sumr[i]);
        }
    }
    for (int j = 0; j < m; j++) {
        if (sumc[j] > 0) {
            ans += sumc[j];
            flow.addEdge(j + n, sink, sumc[j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            flow.addEdge(i, j + n, a[i][j] < 0 ? inf : a[i][j]);
        }
    }
    
    ans -= flow.maxFlow(source, sink);
    cout << ans << "\n";
    
    return 0;
}