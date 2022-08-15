#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;

            if ((n - len) % 2 == 1)
            {
                dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r]);
            } else {
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r]);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}