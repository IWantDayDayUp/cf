#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // dp[0][i]: a_i == 1
    // dp[1][i]: a_i == b_i
    vector<int> b(n + 1);
    vector<vector<int>> dp(2, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];

        if (i > 1)
        {
            dp[0][i] = max(1 - 1 + dp[0][i - 1], abs(1 - b[i - 1]) + dp[1][i - 1]);
            dp[1][i] = max(abs(b[i] - 1) + dp[0][i - 1], abs(b[i - 1] - b[i]) + dp[1][i - 1]);
        } else {
            dp[0][i] = 0;
            dp[1][i] = 0;
        }
    }

    cout << max(dp[0][n], dp[1][n]) << endl;

    return 0;
}