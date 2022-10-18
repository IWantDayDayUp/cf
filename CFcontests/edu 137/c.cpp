#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = 0;
    long long ans = 0;
    long long mn = 1e9;
    while (r < n)
    {
        while (l < n && s[l] == '0')
        {
            l += 1;
        }

        r = l;
        mn = 1e9;
        while (r < n && s[r] == '1')
        {
            mn = min(mn, a[r]);
            ans += a[r];
            r += 1;
        }

        // cout << mn << endl;

        if (l > 0)
        {
            ans += a[l - 1];
            ans -= min(mn, a[l - 1]);
        }

        r += 1;
        l = r;
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