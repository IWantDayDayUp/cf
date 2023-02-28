#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }

    long long mod = 998244353;

    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (a[i - 1][j] != a[i][k])
                {
                    dp[i][k] += dp[i - 1][j];
                    dp[i][k] %= mod;
                }
            }
        }
    }

    cout << ((dp[n - 1][0] + dp[n - 1][1]) % mod) << endl;

    return 0;
}