#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    if (m % 2 == 0)
    {
        cout << 0 << endl;
        return ;
    }

    long long ans = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() % 2 == 1)
        {
            ans = min(ans, a[i]);
        } else {
            for (auto & v : adj[i])
            {
                if (adj[v].size() % 2 == 0)
                {
                    ans = min(ans, a[i] + a[v]);
                }
            }
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