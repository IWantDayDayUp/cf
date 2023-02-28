#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj1(n), adj2(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            if (s[j] == '1')
            {
                adj1[i].push_back(i + j + 1);
                adj2[i + j + 1].push_back(i);
            }
        }
    }

    auto bfs = [&](auto &adj, int s)
    {
        vector<int> dis(n, -1);
        dis[s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto &v : adj[u])
            {
                if (dis[v] == -1)
                {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        return dis;
    };

    vector<int> dis1 = bfs(adj1, 0);
    vector<int> dis2 = bfs(adj2, n - 1);

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (auto &j : adj1[i])
        {
            if (dis1[i] != -1 && dis2[j] != -1)
            {
                int cur = dis1[i] + dis2[j] + 1;

                for (int k = i + 1; k < j; k++)
                {
                    if (ans[k] > cur || ans[k] == -1)
                    {
                        ans[k] = cur;
                    }
                }
            }
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        cout << ans[i] << " \n"[i == n - 2];
    }

    return 0;
}