#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> q(k);
    for (int i = 0; i < k; i++)
    {
        cin >> q[i];
    }
    vector<int> p(k);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j)
    {
        return q[i] < q[j];
    });

    long long temp = 0;
    int r = 0;
    vector<long long> ans(k, 0);
    for (int i = 0; i < k; i++)
    {
        int cur = q[p[i]];
        while (r < n && cur >= a[r])
        {
            temp += a[r];
            r += 1;
        }
        // cout << p[i] << ' ' << temp << endl;

        ans[p[i]] = temp;
    }

    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " \n"[i == k - 1];
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