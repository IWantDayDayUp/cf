#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long mod = 998244353;

    // long long ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     ans += 2 * i - 1;
    //     ans %= mod;
    // }

    cout << (n % mod * ((n + 1) % mod) % mod - n % mod + mod) % mod << endl;

    return 0;
}