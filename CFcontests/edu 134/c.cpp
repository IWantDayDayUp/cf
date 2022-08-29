#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<long long> l(n), r(n);
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

        l[i] = b[it] - a[i];
        r[i] = b[j] - a[i];

        if (it == i)
        {
            j = i - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << l[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << r[i] << " \n"[i == n - 1];
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