#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        a[i].resize(s);

        for (int j = 0; j < s; j++)
        {
            cin >> a[i][j];
            b[--a[i][j]].push_back(i);
        }
    }

    vector<bool> vis(n);
    vector<int> dis(m, -1);
    dis[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto & c : b[cur])
        {
            if (!vis[c])
            {
                vis[c] = true;
                for (auto & u : a[c])
                {
                    if (dis[u] == -1)
                    {
                        dis[u] = dis[cur] + 1;
                        q.push(u);
                    }
                }
            }
        }
    }

    int ans = dis[m - 1];
    if (ans != -1)
    {
        ans--;
    }

    cout << ans << endl;

    return 0;
}