#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);

    long long ans = 0, cur = 1e18;
    long long cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        cnt += a[i] < 0;

        ans += abs(a[i]);
        cur = min(cur, abs(a[i]));
    }

    if (cnt & 1)
    {
        ans -= cur * 2;
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