#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    long long ans = 2e18;

    for (long long i = 1; i <= n; i++)
    {
        long long cur = (m + i - 1) / i;
        if (cur <= n)
        {
            ans = min(ans, i * cur);
        }
        if (i > cur)
        {
            break;
        }
    }

    cout << (ans == 2e18 ? -1 : ans) << endl;

    return 0;
}