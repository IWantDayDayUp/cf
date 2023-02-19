#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> pa(n + 1), pb(n + 1);
    for (int i = 0; i < n; i++)
    {
        long long cur;
        cin >> cur;
        pa[cur] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        long long cur;
        cin >> cur;
        pb[cur] = i + 1;
    }

    long long ans = 0;

    auto calc = [](long long n)
    {
        return n * (1 + n) / 2;
    };

    long long L = min(pa[1], pb[1]);
    long long R = max(pa[1], pb[1]);

    ans = calc(L - 1) + calc(n - R) + calc(max(0ll, R - L - 1));

    for (int cur = 2; cur <= n; cur++)
    {
        long long l = pa[cur], r = pb[cur];
        if (l > r) {
            swap(l, r);
        }

        if ((L < l && l < R) || (L < r && r < R))
        {
            // 出现在中间, 这个时候无法得到 MEX = cur
        } else if (l < L && R < r)
        {
            ans += (L - l) * (r - R);
        } else if (r < L)
        {
            ans += (L - r) * (n - R + 1);
        } else if (R < l)
        {
            ans += L * (l - R);
        }

        L = min(L, l);
        R = max(R, r);
    }

    cout << (ans + 1) << endl;

    return 0;
}