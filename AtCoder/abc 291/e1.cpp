#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        deg[v] += 1;
    }

    vector<int> a(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (q.size() != 1)
        {
            cout << "No" << endl;
            return 0;
        }

        int u = q.front();
        q.pop();

        a[u] = i;

        for (auto &v : adj[u])
        {
            deg[v] -= 1;
            if (deg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}