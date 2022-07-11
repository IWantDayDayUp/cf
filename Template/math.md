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
