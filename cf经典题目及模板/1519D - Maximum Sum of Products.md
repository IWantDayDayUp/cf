# 1519D - Maximum Sum of Products

## 1. 题目

给定两个数组`a` 和 `b`, 可以转置数组`a`的一个子数组(最多一次)

Your task is to reverse such a subarray that the sum $\sum_{i = 1}^{n}a_i * b_i$ is maximized.

## 2. 分析

* 暴力做法: 枚举每一个子数组的边界[l, r], 计算结果, 复杂度 $O(n^3)$

* 进阶做法: 枚举每一个子数组的中心 `p`, 当前子数组[l, r], 扩展为[l - 1, r + 1], 增量为 $a_{l − 1} ∗ b_{r + 1} + a_{r + 1} ∗ b_{l − 1}$

## 3. 代码

```c++
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i] * b[i];
    }

    long long ans = pre[n];

    // 枚举子数组中心位置
    for (int p = 0; p < n; p++)
    {
        // 子数组个数为 `奇数`
        long long cur = a[p] * b[p];
        for (int l = p - 1, r = p + 1; l >= 0 && r < n; l--, r++)
        {
            cur += a[l] * b[r];
            cur += a[r] * b[l];
            ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
        }

        // 子数组个数为 `偶数`
        cur = 0;
        for (int l = p, r = p + 1; l >= 0 && r < n; l--, r++)
        {
            cur += a[l] * b[r];
            cur += a[r] * b[l];
            ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
        }
    }

    cout << ans << endl;

    return 0;
}
```
