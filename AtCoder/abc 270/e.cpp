#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](long long mid)
    {
        long long temp = 0;
        for (long long i = 0; i < n; i++)
        {
            temp += min(a[i], mid);
        }

        return temp <= k;
    };

    long long l = 0, r = k + 1;
    long long need = -1;
    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid + 1;
            need = mid;
        } else {
            r = mid - 1;
        }
    }

    assert(need >= 0);
    for (long long i = 0; i < n; i++)
    {
        k -= min(a[i], need);
        a[i] -= min(a[i], need);
    }
    for (long long i = 0; i < n; i++)
    {
        if (k > 0 && a[i] > 0)
        {
            a[i] -= 1;
            k -= 1;
        }
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}