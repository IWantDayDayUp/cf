#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        long long y;
        cin >> y;

        a[i] = y - a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r)
    {
        long long cur = a[l] + a[r];
        if (cur >= 0)
        {
            ans += 1;
            l += 1;
            r -= 1;
        } else {
            l += 1;
        }
    }

    cout << ans << endl;
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