#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<bool> black(n, true);

    int k;
    cin >> k;
    vector<int> p(k), d(k);
    for (int i = 0; i < k; i++)
    {
        cin >> p[i] >> d[i];
        p[i]--;

        vector<int> dis(n, -1);
        dis[p[i]] = 0;

        queue<int> q;
        q.push(p[i]);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dis[u] < d[i])
            {
                black[u] = false;
            }

            for (auto & v : adj[u])
            {
                if (dis[v] == -1)
                {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    vector<int> dis(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (black[i])
        {
            q.push(i);
            dis[i] = 0;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto & v : adj[u])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (dis[p[i]] != d[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << black[i];
    }
    cout << endl;

    return 0;
}