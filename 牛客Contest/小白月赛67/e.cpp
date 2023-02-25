#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<double> dp(n);
    dp[n - 1] = 0.5 * a[n - 1] + 0.5 * b[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = 0.5 * (min(a[i], dp[i + 1]) + min(b[i], dp[i + 1]));
    }

    cout << fixed << setprecision(6) << dp[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}