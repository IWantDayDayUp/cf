#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 需要修改的数量, 以及每个颜色对应的位置
    int cnt = 0;
    map<int, set<int>> mp, mp2;

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        
        // 需要更改颜色的位置
        if (a[i] != b[i])
        {
            cnt += 1;
            mp[b[i]].insert(i);
        } else {
            mp2[b[i]].insert(i);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }

    vector<int> ans(m, -1);

    // 倒序确定位置(后面会覆盖前面)
    for (int i = m - 1; i >= 0; i--)
    {
        // 画师的颜色
        int color = c[i];
        // 当前画师有修改颜色的位置p, a[p] -> b[p]
        if (mp[color].size() > 0)
        {
            int p = *mp[color].begin();
            mp[color].erase(mp[color].begin());
            ans[i] = p;
            cnt -= 1;
        } 
        // 当前画师没有修改的地方, 就让他被后面的画师覆盖
        else {
            if (mp2[color].size() > 0)
            {
                ans[i] = *mp2[color].begin();
            } else {
                if (i < m - 1)
                {
                    ans[i] = ans[i + 1];
                } else {
                    // 最后一名画师无法被覆盖
                    cout << "NO" << endl;
                    return ;
                }
            }
        }
    }

    if (cnt != 0)
    {
        cout << "NO" << endl;
    } else {
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