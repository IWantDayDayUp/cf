#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i] -= 1;
    }

    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[a[i]] + 1;
    }

    cout << dp[n - 1] << endl;

    return 0;
}