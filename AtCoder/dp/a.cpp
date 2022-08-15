#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 1e9);
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
        }
        if (i > 2)
        {
            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
        }
    }

    cout << dp[n] << endl;

    return 0;
}