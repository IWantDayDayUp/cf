#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> pre(n, 0);
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + (i % 2 == 1 ? 0 : a[i] - a[i - 1]);
    }

    int q;
    cin >> q;

    auto calc = [&](long long x)
    {
        auto it = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
        return pre[it] + (pre[it + 1] - pre[it]) / (a[it + 1] - a[it]) * (x - a[it]);
    };

    while (q--)
    {
        long long l, r;
        cin >> l >> r;

        cout << calc(r) - calc(l) << endl;
    }

    return 0;
}