#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long mod = 998244353;

    long long ans = n % mod;

    if (ans < 0)
    {
        ans += mod;
    }

    cout << ans << endl;

    return 0;
}