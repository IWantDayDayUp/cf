#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
    }

    int q;
    cin >> q;

    vector<int> x(q);
    for (int i = 0; i < q; i++)
    {
        cin >> x[i];
        x[i]--;
    }

    int lo = 0, hi = q + 1;
    while (lo < hi)
    {
        int mid = lo + hi >> 1;

        vector<int> s(n + 1);
        for (int i = 0; i < mid; i++)
        {
            s[x[i] + 1] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            s[i] += s[i - 1];
        }

        bool ok = false;
        for (int i = 0; i < m; i++)
        {
            if (s[r[i]] - s[l[i]] > (r[i] - l[i]) / 2)
            {
                ok = true;
            }
        }

        if (ok)
        {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << (lo > q ? -1 : lo) << endl;
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