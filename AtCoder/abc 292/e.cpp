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
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        q.push(i);

        vector<bool> vis(n, false);
        vis[i] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            ans += 1;

            for (auto &v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    ans -= n + m;

    cout << ans << endl;

    return 0;
}