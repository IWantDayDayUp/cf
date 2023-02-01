#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d;
    long long c;
    cin >> n >> c >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    int l = 0, r = d + 2;
    while (l < r)
    {
        int mid = l + (r - l + 1) / 2;
        long long cnt = 0;

        for (int i = 0; i < d; i++)
        {
            if (i % mid < n)
            {
                cnt += a[i % mid];
            }
        }

        if (cnt >= c)
        {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    if (l == d + 2)
    {
        cout << "Infinity" << endl;
    } else if (l == 0)
    {
        cout << "Impossible" << endl;
    } else {
        cout << l - 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}