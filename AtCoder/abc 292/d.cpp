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

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }

        queue<int> q;
        q.push(i);
        vis[i] = true;

        int N = 0, E = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            N += 1;
            E += adj[u].size();

            for (auto &v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        E /= 2;

        if (N != E)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}