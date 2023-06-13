#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> d(n, -1);
    priority_queue<pair<int, int>> pq;

    auto add = [&](int v, int x)
    {
        if (d[v] < x)
        {
            pq.emplace(d[v] = x, v);
        }
    };

    vector<int> p(n), h(n);
    for (int i = 0; i < k; i++)
    {
        cin >> p[i] >> h[i];

        add(--p[i], h[i]);
    }

    while (!pq.empty())
    {
        auto [x, u] = pq.top();
        pq.pop();

        if (d[u] != x) {
            continue;
        }

        for (auto & v : adj[u])
        {
            add(v, d[u] - 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += d[i] >= 0;
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (d[i] >= 0)
        {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;

    return 0;
}