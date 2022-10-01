#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        mp[p] += 1;
    }

    auto check = [&](int mid)
    {
        // 已经有的
        int k = 0;
        for (int i = 1; i <= mid; i++)
        {
            if (mp[i] > 0)
            {
                k += 1;
            }
        }

        // 还剩less本
        int less = n - k;

        // less / 2: 能买的数量
        return k + less / 2 >= mid;
    };

    int l = 0, r = n;

    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (ans == 0)
    {
        cout << 0 << endl;
    } else {
        if (check(ans))
        {
            cout << ans << endl;
        } else {
            cout << ans - 1 << endl;
        }
    }

    // cout << ans << endl;

    return 0;
}