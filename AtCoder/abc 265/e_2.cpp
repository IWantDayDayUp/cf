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

    // dp[i][j][k]: the number of paths in which you make each of the moves x, y, and z times, during the n teleportations
    vector<vector<long long>> dp(1, vector<long long>(1));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        vector<vector<long long>> newdp(i + 2, vector<long long>(i + 2));
        
        for (long long a = 0; a <= i; a++)
        {
            for (long long b = 0; b <= i; b++)
            {
                long long x = a * dx[0] + b * dx[1] + (i - a - b) * dx[2];
                long long y = a * dy[0] + b * dy[1] + (i - a - b) * dy[2];

                for (long long k = 0; k < 3; k++)
                {
                    if (!obstacles.count({x + dx[k], y + dy[k]}))
                    {
                        newdp[a + (k == 0)][b + (k == 1)] += dp[a][b];
                        newdp[a + (k == 0)][b + (k == 1)] %= mod;
                    }
                }
            }
        }

        swap(dp, newdp);
    }

    long long ans = 0;
    for (int a = 0; a <= n; a++)
    {
        for (int b = 0; b <= n; b++)
        {
            ans += dp[a][b];
            ans %= mod;
        }
    }
    
    cout << ans << endl;

    return 0;
}