#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<double> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            dp[i] += (1.0 / 6.0) * max(dp[i - 1], (double)j);
        }
    }

    cout << fixed << setprecision(10) << dp[n] << endl;

    return 0;
}