#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<long long>> dp(3, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b[i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
    }

    cout << max({dp[0][n], dp[1][n], dp[2][n]}) << endl;

    return 0;
}