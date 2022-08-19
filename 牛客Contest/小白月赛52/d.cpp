#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<long long> a(n), b(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (sum < s)
    {
        cout << -1 << endl;
        return 0;
    }

    int l = 1, r = 1e9;

    auto check = [&](int mid)
    {
        long long cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] > mid)
            {
                if (cur >= s) return true;
                cur = 0;
            } else {
                cur += a[i];
            }
        }

        if (cur >= s) return true;

        for (int i = 0; i < n; i++)
        {
            if (b[i] > mid)
            {
                if (cur >= s) return true;
                break;
            } else {
                cur += a[i];
            }
        }

        return false;
    };

    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}