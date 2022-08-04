#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<long long> deg(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        deg[u] += 1;
        adj[v].emplace_back(u);
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!deg[i])
        {
            q.emplace(i);
        }
    }

    vector<long long> dis(n, 0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto & v : adj[u])
        {
            deg[v] -= 1;

            if (!deg[v])
            {
                q.emplace(v);
            }

            dis[v] = max(dis[v], dis[u] + 1);
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dis[i] << " \n"[i == n - 1];
    // }

    long long ans = 0;
    long long mod = 998244353;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            continue;
        }

        // 
        if (dis[i] == 0)
        {
            ans = max(ans, nums[i]);
        } else {
            if (nums[i] > 1)
            {
                ans = max(ans, (dis[i] + 1 + nums[i] - 1) % mod);
            } else {
                ans = max(ans, (dis[i] + 1) % mod);
            }
            // ans = max(ans, )
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}