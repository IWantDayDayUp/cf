#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
#define ll long long
ll mod = 1e9 + 7;
int a[maxn], mi[maxn];
int main()
{
    ll n, ans = 0;
    cin >> n;
    mi[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mi[i] = mi[i - 1] * 2 % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        ll now = 0;
        if (i * 2 <= n)
        {
            now += a[i] ^ a[i * 2];
        }
        if (i * 2 + 1 <= n)
        {
            now += a[i] ^ a[i * 2 + 1];
            now += a[i] ^ a[i * 2 + 1] ^ a[i * 2];
            now += a[i * 2] ^ a[i * 2 + 1];
            ans += now * mi[n - 3];
        }
        else
        {
            ans += now * mi[n - 2];
        }
        ans %= mod;
    }
    cout << ans << endl;
}