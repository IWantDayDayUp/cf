#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<long long> c(n), a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<long long> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
        {
            dp[i] = c[i] + 1;
        } else {
            if (i == 1)
            {
                dp[i] = dp[i - 1] + c[i] + abs(a[i] - b[i]) + 1;
            } else {
                dp[i] = max(dp[i - 1] + c[i] - abs(a[i] - b[i]) + 1, c[i] + abs(a[i] - b[i]) + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
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