#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i] * b[i];
    }

    long long ans = pre[n];

    // 枚举中心位置
    for (int p = 0; p < n; p++)
    {
        // 奇数
        long long cur = a[p] * b[p];
        for (int l = p - 1, r = p + 1; l >= 0 && r < n; l--, r++)
        {
            cur += a[l] * b[r];
            cur += a[r] * b[l];
            ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
        }

        // 偶数
        cur = 0;
        for (int l = p, r = p + 1; l >= 0 && r < n; l--, r++)
        {
            cur += a[l] * b[r];
            cur += a[r] * b[l];
            ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
        }
    }

    cout << ans << endl;

    return 0;
}