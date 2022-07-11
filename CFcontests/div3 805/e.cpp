#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


void slove() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        mp[a].emplace_back(i);
        mp[b].emplace_back(i);
    }

    bool ok = true;
    for (auto & p : mp)
    {
        if (p.second.size() != 2)
        {
            ok = false;
            break;
        }
    }

    if (!ok)
    {
        cout << "NO" << endl;
    } else {
        map<int, vector<int>> adj;
        for (auto & p : mp)
        {
            int u = p.second[0], v = p.second[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        vector<bool> vis(n, false);
        vector<int> col(n, -1);
        bool ans = true;

        function<void(int)> dfs = [&](int u)
        {
            vis[u] = true;
            for (auto & v : adj[u])
            {
                if (!vis[v])
                {
                    col[v] = col[u] ^ 1;
                    dfs(v);
                }

                if (col[u] == col[v])
                {
                    ans = false;
                }
            }
        };

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                col[i] = 1;
                dfs(i);
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
    
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