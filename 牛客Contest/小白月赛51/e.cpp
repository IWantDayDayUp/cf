#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    vector<long long> a(x), b(x);
    long long mx = 1;
    for (int i = 0; i < x; i++)
    {
        cin >> a[i] >> b[i];
        mx = max(mx, a[i]);
    }

    long long n;
    cin >> n;

    long long ans = 0;

    if (n >= mx)
    {
        ans = 1;
    } else {
        mx = 1;

        for (int i = 0; i < x; i++)
        {
            long long l = max(mx, b[i] * n), r = min(a[i] - 1, (n + 1) * b[i] - 1);

            if (l <= r) ans += r - l + 1;

            mx = max(mx, a[i]);
        }
    }

    cout << ans << endl;

    return 0;
}