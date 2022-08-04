#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<long long> a(n, 0), b(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;

        cin >> a[i] >> b[i];

        adj[p].emplace_back(i);
    }

    vector<int> ans(n, 0);

    vector<long long> da(n, 0), db(n, 0), s;
    function<void(int)> dfs = [&](int u)
    {
        s.emplace_back(db[u]);

        if (u > 0)
        {
            ans[u] = upper_bound(s.begin(), s.end(), da[u]) - s.begin() - 1;
        }

        for (auto & v : adj[u])
        {
            da[v] = a[v] + da[u];
            db[v] = b[v] + db[u];
            dfs(v);
        }
        s.pop_back();
    };

    dfs(0);

    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
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