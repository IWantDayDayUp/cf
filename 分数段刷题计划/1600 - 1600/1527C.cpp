#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> dp(n);

    long long ans = 0;
    map<long long, long long> mp;

    for (int i = 0; i < n; i++)
    {
        dp[i] += mp[a[i]];
        mp[a[i]] += (i + 1);

        if (i > 0)
        {
            dp[i] += dp[i - 1];
        }

        ans += dp[i];
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}