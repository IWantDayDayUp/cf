#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        mp[num] += 1;
    }

    vector<vector<vector<double>>> dp(n + 2, vector<vector<double>>(n + 2, vector<double>(n + 2, 0)));

    for (int k = 0; k <= n; k++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i <= n; i++)
            {
                if (i || j || k)
                {
                    int d = i + j + k;
                    
                    if (i > 0) dp[i][j][k] += dp[i - 1][j][k] * i / d;
                    if (j > 0) dp[i][j][k] += dp[i + 1][j - 1][k] * j / d;
                    if (k > 0) dp[i][j][k] += dp[i][j + 1][k - 1] * k / d;

                    dp[i][j][k] += 1.0 * n / d;
                }
            }
        }
    }

    cout << fixed << setprecision(15) << dp[mp[1]][mp[2]][mp[3]] << endl;;

    return 0;
}