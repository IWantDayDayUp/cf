#include <bits/stdc++.h>

using namespace std;

int main()
{
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
    }

    vector<int> length(n, -1);
    auto dfs = [&](int u, auto dfs)
    {
        if (length[u] != -1)
        {
            return length[u];
        }

        length[u] = 0;
        for (auto &v : adj[u])
        {
            length[u] = max(length[u], dfs(v, dfs) + 1);
        }

        return length[u];
    };

    int l = 0;
    for (int i = 0; i < n; i++)
    {
        l = max(l, dfs(i, dfs));
    }

    if (l == n - 1)
    {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << n - length[i] << " \n"[i == n - 1];
        }
    } else
    {
        cout << "No" << endl;
    }

    return 0;
}