#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, k;
    cin >> n >> k;

    vector<long long> dp(n + 1, 0), ans(n + 1, 0);
    long long mod = 998244353;
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // 第 i 次操作时的最小步长
        long long cur = k + i - 1;

        // 每次操作必须 `至少` 跳 cur
        // 整体右移, 表示跳 cur
        for (int j = n; j >= cur; j--)
        {
            dp[j] = dp[j - cur];
        }
        for (int j = 0; j < cur; j++)
        {
            dp[j] = 0;
        }

        // 转移, 正向枚举, cur 的倍数也随之更新
        for (int j = cur; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - cur]) % mod;
        }

        // 累加答案
        for (int j = cur; j <= n; j++)
        {
            ans[j] = (ans[j] + dp[j]) % mod;
        }

        // 终止条件
        // 每次操作都必须跳 cur 步, 就是一个 [k, k + 1, k + 2, ..., k + i] 的等差数列求和
        if (1ll * i * (k + k + i - 1) > n * 2)
        {
            break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    slove();

    return 0;
}