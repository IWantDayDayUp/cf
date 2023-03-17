# math

## 1. 阶乘

```c++

int mod = 1e9 + 7;

int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * i % mod;
    }
    return res;
}
```

## 2. 快速幂

```c++
int fast_pow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = a * 1ll * a % mod;
            p /= 2;
        }
        else
        {
            res = res * 1ll * a % mod;
            p--;
        }
    }
    return res;
}
```

## 2. 组合数

组合数定义: 从 `n` 个不同元素中, 任取 `k`(k <= n) 个元素, 不管其顺序组成一组, 所有这样的组合叫做 `组合数`

$C(n, k) = \frac{n!}{(n - k)! * k!}(k <= n)$

```c++

int C(int n, int k)
{
    return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}

```

## 3. GCD

GCD: greatest common divisor 最大公约数

[例题 cf 1458A Row GCD](../分数段刷题计划/1600%20-%201600/1458A.cpp)

basic properties of GCD: $GCD(x, y) = GCD(x − y, y)$

multiple arguments: $GCD(x, y, z, …) = GCD(x − y, y, z, …)$

## 4. 精度问题

```c++
cout << fixed << setprecision(17) << num1 << endl;
```

## 5. 矩阵快速幂

例题: [abc293_e](https://atcoder.jp/contests/abc293/tasks/abc293_e)

```c++
#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>> a, vector<vector<long long>> b, long long mod)
{
    int n = a.size();
    vector<vector<long long>> res(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }

    return res;
}

vector<vector<long long>> mat_pow(vector<vector<long long>> a, long long b, long long mod)
{
    int n = a.size();
    vector<vector<long long>> res(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }

    while (b)
    {
        if (b & 1)
        {
            res = mat_mul(res, a, mod);
        }
        a = mat_mul(a, a, mod);
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, x, m;
    cin >> a >> x >> m;

    vector<vector<long long>> f = {{a, 1}, {0, 1}}, g = mat_pow(f, x, m);

    cout << g[0][1] << endl;

    return 0;
}
```