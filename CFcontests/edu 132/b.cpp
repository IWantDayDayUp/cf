#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> diff(n, 0);
    vector<long long> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (i > 0)
        {
            diff[i] = a[i - 1] - a[i] >= 0 ? a[i - 1] - a[i] : 0;
        }
        pre[i + 1] = pre[i] + diff[i]; 
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << pre[i] << " \n"[i == n];
    // }

    vector<long long> nums(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            nums[i] = a[i + 1] - a[i] >= 0 ?  a[i + 1] - a[i] : 0;
        }
        suf[i] = suf[i + 1] + nums[i];
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << suf[i] << " \n"[i == n];
    // }

    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;

        if (s <= t)
        {
            cout << pre[t] - pre[s] << endl;
        } else {
            cout << suf[t - 1] - suf[s - 1] << endl;
        }
    }

    return 0;
}