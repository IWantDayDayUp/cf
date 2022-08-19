#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    long long ans = 0;
    while (n > x)
    {
        ans += 1;
        n /= 2;
    }

    if (n > 0)
    {
        ans += 1;
    }

    cout << ans << endl;

    return 0;
}