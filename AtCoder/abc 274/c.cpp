#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> dp(2 * n + 5, 0);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        long long cur = a[i];

        dp[2 * (i + 1) - 1] = dp[cur - 1] + 1;
        dp[2 * (i + 1)] = dp[cur - 1] + 1;
    }

    for (int i = 0; i < 2 * n + 1; i++)
    {
        cout << dp[i] << endl;
    }

    return 0;
}