#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long d;
    cin >> n >> m >> d;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = -1;

    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(b.begin(), b.end(), a[i] + d);

        if (it != b.begin())
        {
            long long cur = *(it - 1);
            if (cur >= a[i] - d)
            {
                ans = max(ans, a[i] + cur);
            }
        }
    }

    cout << ans << endl;

    return 0;
}