#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<long long> value(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);

        value[u] += a[v];
        value[v] += a[u];
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sort(p.begin(), p.end(), [&](int c, int d)
        {
            return value[c] < value[d];
        });

        int u = p[i];
        long long num = a[u];

        // cout << u << " \n"[i == n - 1];

        ans = max(ans, value[u]);
        value[u] = 0;

        for (auto & v : adj[u])
        {
            value[v] -= num;
        }
    }

    cout << ans << endl;

    return 0;
}