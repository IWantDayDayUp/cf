#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long x, y, z;
    cin >> x >> y >> z;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if (a[u] == a[v])
        {
            adj[u].emplace_back(make_pair(v, min(x, z + y)));
            adj[v].emplace_back(make_pair(u, min(x, z + y)));
        } else {
            adj[u].emplace_back(make_pair(v, min(y, z + x)));
            adj[v].emplace_back(make_pair(u, min(y, z + x)));
        }
    }

    // for (auto e : adj[1])
    // {
    //     cout << e.first << ' ' << e.second << endl;
    // }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.emplace(make_pair(0, 1));

    vector<long long> dis(n + 1, 1e9);
    dis[1] = 0;

    while (!q.empty())
    {
        int cur = q.top().second;
        long long d = q.top().first;
        q.pop();

        // cout << cur << ' ' << d << endl;

        if (d > dis[cur]) continue;

        if (cur == n)
        {
            cout << d << endl;
            return 0;
        }

        for (auto & e : adj[cur])
        {
            long long w = e.second;
            int v = e.first;

            // cout << v << ' ' << w << endl;

            if (dis[v] > dis[cur] + w)
            {
                dis[v] = dis[cur] + w;
                q.emplace(make_pair(dis[v], v));
            }
        }
    }



    return 0;
}