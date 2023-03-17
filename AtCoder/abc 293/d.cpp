#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++)
    {
        int a, c;
        char b, d;

        cin >> a >> b >> c >> d;
        a--;
        c--;

        adj[a].push_back(c);
        adj[c].push_back(a);

        deg[a] += 1;
        deg[c] += 1;
    }

    int x = 0, y = 0;

    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = true;

        queue<int> q;
        q.push(i);

        bool ok = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (deg[u] != 2) 
            {
                ok = false;
            }

            for (auto &v : adj[u])
            {
                if (vis[v])
                {
                    continue;
                }

                q.push(v);
                vis[v] = true;
            }
        }

        if (ok) {
            x += 1;
        } else {
            y += 1;
        }
    }

    cout << x << ' ' << y << endl;

    return 0;
}