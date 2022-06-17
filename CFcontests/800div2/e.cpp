#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        adj[v].emplace_back(u);
    }

    vector<int> dis(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(make_pair(0, n - 1));

    while (!q.empty())
    {
        int d = q.top().first, cur = q.top().second;
        q.pop();

        if (dis[cur] != -1)
        {
            continue;
        }
        dis[cur] = d;

        for (auto & u : adj[cur])
        {
            deg[u]--;
            q.emplace(make_pair(d + deg[u] + 1, u));
        }
    }

    cout << dis[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    slove();

    return 0;
}