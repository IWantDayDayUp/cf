#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 2, 0.0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] += dp[i - 1][j] * (1 - a[i]);
            dp[i][j + 1] += dp[i - 1][j] * a[i];
        }
    }

    double ans = 0.0;
    for (int i = 1; i <= n; i++)
    {
        if (2 * i > n)
        {
            ans += dp[n][i];
        }
    }

    cout << fixed << setprecision(11) << ans <<  endl;

    return 0;
}