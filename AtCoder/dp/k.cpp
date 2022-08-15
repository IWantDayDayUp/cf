#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<bool> dp(k + 1, false);
    for (int i = 1; i <= k; i++)
    {
        bool ok = true;
        for (int j = 1; j <= n; j++)
        {
            if (i >= a[j])
            {
                ok &= dp[i - a[j]];
            }
        }

        if (!ok)
        {
            dp[i] = true;
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;

    return 0;
}