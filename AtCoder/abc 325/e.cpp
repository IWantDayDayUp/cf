#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long A, B, C;
    cin >> n >> A >> B >> C;

    const long long inf = LONG_LONG_MAX;

    vector<vector<long long>> adj1(n, vector<long long>(n));
    vector<vector<long long>> adj2(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long d;
            cin >> d;

            adj1[i][j] = d * A;
            adj2[i][j] = d * B + C;
        }
    }

    vector<long long> disX(n, inf), disY(n, inf);
    disX[0] = 0;
    disY[n - 1] = 0;

    auto dijkstra = [&](vector<long long> &dis, vector<vector<long long>> adj)
    {
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            int x = -1;
            for (int j = 0; j < n; j++)
            {
                if (!vis[j] && (x == -1 || dis[j] < dis[x]))
                {
                    x = j;
                }
            }
            vis[x] = true;
            for (int j = 0; j < n; j++)
            {
                dis[j] = min(dis[j], dis[x] + adj[x][j]);
            }
        }

    };

    dijkstra(disX, adj1);
    dijkstra(disY, adj2);

    long long ans = inf;

    for (int i = 0; i < n; i++)
    {
        // cout << disX[i] << ' ' << disY[i] << endl;
        ans = min(ans, disX[i] + disY[i]);
    }

    cout << ans << endl;

    return 0;
}