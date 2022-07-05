#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<i64, i64>> item(n);
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].second >> item[i].first;
    }
    sort(item.begin(), item.end());

    // 要购买的数量
    i64 res = item[n - 1].second;
    // 目前已购买的数量
    i64 cur = 0;
    i64 ans = 0;
    for (int i = 0, j = n - 1; i <= j; i++)
    {
        // 刚开始数量不够, 无法打折, 只能先全额付款, 先购买难凑单的(即: b_i 最大的)
        while (i <= j && cur < item[i].first)
        {
            // 这里是凑单的, 只要购买最小数量, 达到打折要求就行(所以min), 多买会亏

            // 为了凑打折限度, 需要全额购买的最小数量
            i64 t = min(res, item[i].first - cur);
            cur += t;
            ans += 2 * t;

            // 全额付款后, 该种商品仍需购买的数量
            res -= t;
            if (res == 0)
            {
                j--;
                res = item[j].second;
            }
        }
        if (i > j)
        {
            break;
        }

        // 达到打折要求了, 该种商品全部打折
        i64 t = i == j ? res : item[i].second;
        ans += t;
        cur += t;
    }

    cout << ans << "\n";

    return 0;
}