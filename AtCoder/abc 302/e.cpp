#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> deg(n, 0);
    vector<set<int>> adj(n);

    int ans = n;

    while (q--)
    {
        int o;
        cin >> o;

        if (o == 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            ans -= !deg[u]++;
            ans -= !deg[v]++;

            adj[u].insert(v);
            adj[v].insert(u);
        } else {
            int u;
            cin >> u;
            u--;

            ans += (deg[u] > 0);
            deg[u] = 0;

            for (auto & v : adj[u])
            {
                ans += !--deg[v];
                adj[v].erase(u);
            }
            adj[u].clear();
        }

        cout << ans << endl;
    }

    return 0;
}