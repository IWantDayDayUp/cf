#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long ans = -1e18;
    long long cur = 0;
    long long s = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i <= m)
        {
            s += a[i];
            cur += i * a[i];
            if (i == m)
            {
                ans = max(ans, cur);
            }
        } else {
            cur += m * a[i] - s;
            s += a[i] - a[i - m];
            ans = max(ans, cur);
        }
    }

    cout << ans << endl;

    return 0;
}