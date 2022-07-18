#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    long long n, k;
    cin >> n >> k;

    vector<long long> coins(n);
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];

        // 失去的金币(上取整)
        prefix[i + 1] = prefix[i] + (coins[i] + 1) / 2;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -k;

    for (int i = 0; i < n; i++)
    {
        // 使用好钥匙
        // 需要花费 `k` 金币买 `好` 钥匙, 然后得到该箱子里的金币
        dp[i + 1][0] = max(dp[i][0], dp[i][1]) - k + coins[i];

        // 使用坏钥匙
        // 不需要花费金币买钥匙, 但是(i, ..., n - 1)所有的箱子里的金必都会减半(下取整)
        // 不就是说, 时候箱子都会失去 (上取整) 个金币???
        // 前缀和剪掉就行吧??
        // dp[i + 1][0] = max(dp[i][0], dp[i][1]) - (prefix[n] - prefix[i]) + (coins[i] / 2);
        dp[i + 1][0] = max(dp[i][0], dp[i][1]) + (coins[i] / 2);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

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