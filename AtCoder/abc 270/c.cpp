#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> fa(n + 1, -1);
    queue<int> q;
    q.emplace(y);
    fa[y] = y;

    while (!q.empty())
    {
        int num = q.size();
        for (int _ = 0; _ < num; _++)
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (fa[v] != -1)
                {
                    continue;
                }
                fa[v] = u;

                if (v == x)
                {
                    cout << x << ' ';
                    while (fa[x] != y)
                    {
                        cout << fa[x] << ' ';
                        x = fa[x];
                    }
                    cout << y << endl;
                    return 0;
                }

                q.emplace(v);
            }
        }
    }

    // cout << x << ' ';
    // while (fa[x] != y)
    // {
    //     x = fa[x];
    //     cout << fa[x] << ' ';
    // }
    // cout << y << endl;

    return 0;
}