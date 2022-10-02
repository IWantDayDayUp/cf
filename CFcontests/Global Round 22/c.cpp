#include <bits/stdc++.h>

using namespace std;

int dp[101][101][2][2];

// 记忆化搜索
// even: 剩余偶数个数
// odd: 剩余奇数个数
// x: 当前Alice奇偶性, 0为偶, 1为奇
// p: 当前是谁的回合, 0为Alice, 1为Bob
int calc(int even, int odd, int x, int p)
{
    if (dp[even][odd][x][p] != -1)
    {
        return dp[even][odd][x][p];
    }

    int &res = dp[even][odd][x][p];
    res = 0;
    if (!even && !odd)
    {
        res = !x ^ p;
    } else {
        if (even)
        {
            res |= !calc(even - 1, odd, x, !p);
        }
        if (odd)
        {
            res |= !calc(even, odd - 1, x ^ !p, !p);
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<int> cnt(2);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] &= 1;

        // 统计奇偶
        cnt[a[i]] += 1;
    }

    memset(dp, -1, sizeof(dp));

    cout << (calc(cnt[0], cnt[1], 0, 0) ? "Alice" : "Bob") << endl;
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