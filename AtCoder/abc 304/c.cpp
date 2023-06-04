#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cur = pow(a[i] - a[j], 2) + pow(b[i] - b[j], 2);

            if (cur <= d * d)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    queue<int> q;
    q.push(0);

    vector<bool> vis(n, false);
    vis[0] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto & v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << (vis[i]? "Yes" : "No") << endl;
    }

    return 0;
}