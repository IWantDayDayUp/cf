#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    vector<long long> a(n), b(n);
    vector<long long> dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];

        if (i > 0)
        {
            dp[i] = dp[i - 1] + a[i] + b[i];
        } else {
            dp[i] = a[i] + b[i];
        }
    }

    long long ans = numeric_limits<long long>::max();

    for (int i = 0; i < n; i++)
    {
        if (i + 1 > x)
        {
            break;
        }
        ans = min(ans, dp[i] + (long long)b[i] * (x - i - 1));
    }

    cout << ans << endl;

    return 0;
}