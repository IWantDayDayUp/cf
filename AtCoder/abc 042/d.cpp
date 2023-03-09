#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7ll;
const int N = 2 * 1e5 + 10;

long long fac[N];

long long pw(long long a, long long p)
{
    long long res = 1;
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

long long inv(long long x)
{
    return pw(x, mod - 2ll);
}

long long path(long long a, long long b)
{
    long long ans = fac[a + b];
    ans = (ans * inv(fac[a])) % mod;
    ans = (ans * inv(fac[b])) % mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, a, b;
    cin >> h >> w >> a >> b;

    fac[0] = 1ll;
    for (int i = 1; i < N; i++)
    {
        fac[i] = (i * fac[i - 1]) % mod;
    }

    long long ans = 0ll;

    for (int i = h - a, j = b + 1; i > 0 && j <= w; i--, j++)
    {
        ans += (path(i - 1, j - 1) * path(h - i, w - j)) % mod;
    }

    ans = (ans % mod + mod) % mod;

    cout << ans << endl;

    return 0;
}