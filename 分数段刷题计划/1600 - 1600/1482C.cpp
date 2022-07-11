#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0);
    vector<vector<int>> a(m);
    vector<int> ans(m, -1);

    int lim = (m + 1) / 2;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int p;
            cin >> p;
            a[i].emplace_back(--p);
        }

        // 这一天只有一个人可以选择, 就直接确定下来
        if (num == 1)
        {
            cnt[a[i][0]] += 1;
            ans[i] = a[i][0];
        }
    }

    // 某人必须邀请的次数超过限制, 不可替换, 就没有方案
    if (*max_element(cnt.begin(), cnt.end()) > lim)
    {
        cout << "NO" << endl;
    } else {
        // 确定剩余的人选
        for (int i = 0; i < m; i++)
        {
            if (a[i].size() >= 2)
            {
                for (auto & p : a[i])
                {
                    if (cnt[p] < lim)
                    {
                        cnt[p] += 1;
                        ans[i] = p;
                        break;
                    }
                }
            }
        }

        cout << "YES" << endl;
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] + 1 << " \n"[i == m - 1];
        }
    }
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