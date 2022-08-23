#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> dx(3), dy(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> dx[i] >> dy[i];
    }

    set<pair<long long, long long>> obstacles;
    for (int i = 0; i < m; i++)
    {
        long long x, y;
        cin >> x >> y;

        obstacles.insert({x, y});
    }

    long long mod = 998244353;

    // dp[n][i][j]: the number of paths that end up in (x,y) after n teleportations
    map<pair<long long, long long>, long long> dp;
    // dp[make_pair(0, 0)] = 1;
    dp[{0, 0}] = 1;

    for (int i = 0; i < n; i++)
    {
        map<pair<long long, long long>, long long> newdp;
        for (auto & p : dp)
        {
            long long x = p.first.first, y = p.first.second;
            long long val = p.second;

            for (int j = 0; j < 3; j++)
            {
                long long nx = x + dx[j], ny = y + dy[j];

                if (!obstacles.count({nx, ny}))
                {
                    newdp[{nx, ny}] += val;
                    newdp[{nx, ny}] %= mod;
                }
            }
        }

        swap(dp, newdp);
    }

    long long ans = 0;
    for (auto & p : dp)
    {
        ans += p.second;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}