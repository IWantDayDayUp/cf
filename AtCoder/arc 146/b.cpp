#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long > a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<long long> cnt(30, 0);
    vector<long long> cnt2(30, 0);
    for (int i = 0; i < k; i++)
    {
        long long cur = 0;
        
        for (int j = 0; j < 30; j++)
        {

            if (a[i] & (1 << j))
            {
                cnt[j] += 0;
                // cout << 0 << ' ';
            } else {
                cnt2[j] += 1;
                cnt[j] += (1 << j) - cur;
                // cout << ((1 << j) - cur) << ' ';
            }

            cur += (1 << j) & a[i];
            // cout << cur << endl;
        }
    }

    // for (int i = 0; i < 32; i++)
    // {
    //     cout << cnt[i] << " \n"[i == 31];
    // }

    int mx = 0;
    while ((1 << mx) < a[0])
    {
        mx += 1;
    }
    // cout << mx << endl;

    long long ans = 0;
    for (int i = mx; i >= 0; i--)
    {
        if (m >= cnt[i])
        {

            for (int j = i - 1; j >= 0; j--)
            {
                cnt[j] += cnt2[i] * (1 << j);
            }

            ans |= (1 << i);
            m -= cnt[i];
        }

        if (cnt[i] == 0)
        {
            ans |= (1 << i);
        }

        for (int j = mx; j >= 0; j--)
        {
            cout << cnt[j] << " \n"[j == 0];
        }
    }

    cout << ans << endl;

    return 0;
}