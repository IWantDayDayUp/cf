#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].emplace_back(make_pair(v, i));
        adj[v].emplace_back(make_pair(u, i));
        deg[u]++;
        deg[v]++;
    }
    if (*max_element(deg.begin(), deg.end()) > 2)
    {
        cout << -1 << endl;
        return ;
    }

    vector<int> ans(n - 1, 0);
    function<void(int, int, int c)> dfs = [&](int v, int p, int c)
    {
        for (auto & pa : adj[v])
        {
            if (pa.first == p) continue;
            ans[pa.second] = c;
            dfs(pa.first, v, c ^ 1);
        }
    };

    dfs(min_element(deg.begin(), deg.end()) - deg.begin(), -1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] + 2 << " \n"[i == n - 2];
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