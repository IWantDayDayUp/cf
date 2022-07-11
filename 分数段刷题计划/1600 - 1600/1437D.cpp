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
    }

    // 层数
    int ans = 0;

    // 每一层的节点数, 每个节点都要携带一段递增序列
    int pre = 1;

    // 当前递增序列的个数, 超过上一层节点个数, 就要开启下一层
    int cur = 0;

    // 表示当前层的节点个数
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cnt += 1;
        // cout << cnt << endl;
        if (i == n - 1 || a[i] > a[i + 1])
        {
            cur += 1;
            // cout << cur << endl;
            if (cur == pre || (i == n - 1 && cnt > 0))
            {
                // cout << i << endl;
                pre = cnt;
                ans += 1;

                cnt = 0;
                cur = 0;
            }
        }
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