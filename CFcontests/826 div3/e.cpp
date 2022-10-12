#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i + a[i] <= n)
        {
            dp[i + a[i]] |= dp[i - 1];
        }

        if (i - a[i] >= 1)
        {
            dp[i] |= dp[i - a[i] - 1];
        }
    }

    cout << (dp[n] ? "YES" : "NO") << endl;
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