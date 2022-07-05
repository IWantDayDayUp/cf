#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    // string s;
    // cin >> s;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    set<int> all;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; 
        cin >> u >> v;
        u--;
        v--;

        all.insert(u);
        all.insert(v);

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u] += 1;
        deg[v] += 1;
    }

    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
        {
            deg[i] -= 1;
            dq.emplace_back(i);
        }
    }

    while (!dq.empty() && k--)
    {
        int cnt = dq.size();
        while (cnt--)
        {
            int cur = dq.front();
            dq.pop_front();

            all.erase(cur);

            for (auto v : adj[cur])
            {
                deg[v] -= 1;
                if (deg[v] == 1)
                {
                    dq.emplace_back(v);
                }
            }
        }
    }

    cout << all.size() << endl;
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