#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    long long mod = 998244353;

    long long x = (a % mod) % mod * (b % mod) % mod * (c % mod) % mod;
    long long y = (d % mod) % mod * (e % mod) % mod * (f % mod) % mod;

    cout << (x + mod - y) % mod << endl;

    return 0;
}