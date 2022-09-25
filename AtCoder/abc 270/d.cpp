#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    // DP[n]= the number of stones that the first player can take if the game starts with a pile with n stones
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <k; j++)
        {
            if (i >= a[j])
            {
                dp[i] = max(dp[i], i - dp[i - a[j]]);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}