#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(m + 2);
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        long long s;
        cin >> l >> r >> s;

        a[l] += s;
        a[r + 1] -= s;

        total += s;
    }

    long long mn = 1e18;
    for (int i = 1; i <= m; i++)
    {
        a[i] += a[i - 1];
        mn = min(mn, a[i]);
    }

    cout << total - mn << endl;

    return 0;
}