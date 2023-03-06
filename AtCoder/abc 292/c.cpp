#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long ans = 0;

    vector<long long> dp(n + 1, 0ll);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            dp[i * j] += 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ans += dp[i] * dp[n - i];
    }

    cout << ans << endl;

    return 0;
}