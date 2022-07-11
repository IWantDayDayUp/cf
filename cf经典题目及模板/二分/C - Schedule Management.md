# Schedule Management

## 1. 题目

有 `n` 个工人, `m` 个工作

每个工作 `i` 有一个匹配的工作下标 `p_i`, 表示该工作被这个工人完成只需 `1h`, 被其他人完成则需要 `2h`

每个工人独立工作, 互不影响

问: 每个工作分配一个工人, 求完成所有工作需要花费的 `最小时间`

## 2. 分析

## 3. 代码

```c++
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++)
    {
        int idx;
        cin >> idx;
        idx--;

        cnt[idx] += 1;
    }

    auto check = [&](int mid)
    {
        // 重点:
        // time: 记录多余的时间里可以完成的额外工作数量(2h/个)
        // work: 记录每个工人再规定时间内不能完成的任务数量(1h/个)
        long long time = 0, work = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] >= mid)
            {
                work += cnt[i] - mid;
            } else {
                time += (mid - cnt[i]) / 2;
            }
        }

        return time >= work;
    };

    long long l = *min_element(cnt.begin(), cnt.end());
    long long r = *max_element(cnt.begin(), cnt.end());

    while (l < r)
    {
        long long mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
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
```
