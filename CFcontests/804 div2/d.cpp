#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == -1)
        {
            continue;
        }

        // 统计每个数的出现次数, 以及最大次数
        vector<int> cnt(n);
        int mx = 0;

        for (int j = i; j <= n; j++)
        {
            // 统计出现次数
            if (j > i)
            {
                mx = max(mx, ++cnt[a[j - 1]]);
            }

            // 区间[i, j]满足: 偶数个数, 且最大频次不超过区间个数的一半, 就能将整个区间全部删掉
            if ((j - i) % 2 == 0 && mx * 2 <= j - i)
            {
                if (j == n)
                {
                    dp[n] = max(dp[n], dp[i]);
                } else if (i == 0 || a[i - 1] == a[j])
                {
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }
    }

    cout << dp[n] << endl;
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