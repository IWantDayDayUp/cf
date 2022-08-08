#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, l, r;
    cin >> n >> l >> r;

    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long ans = 1e18;

    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = min(pre[i - 1] + a[i], l * i);
    }

    vector<long long> suf(n + 2, 0);
    for (int i = n; i >= 1; i--)
    {
        suf[i] = min(suf[i + 1] + a[i], r * (n + 1 - i));
    }

    for (int i = 1; i <= n; i++)
    {
        // left
        ans = min(ans, pre[i] + suf[i + 1]);
        // right
        ans = min(ans, pre[i - 1] + suf[i]);
    }

    cout << ans << endl;

    return 0;
}