#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> pre(n, 0), suf(n, 0);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        pre[i] = cnt;
        cnt += a[i] == 0;

        if (a[i] == 1)
        {
            cnt = 0;
        }
    }

    cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = cnt;
        cnt += a[i] == 0;

        if (a[i] == 1)
        {
            cnt = 0;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        ans += 1ll * (pre[i] + 1) * (suf[i] + 1);
    }

    cout << ans << endl;

    return 0;
}