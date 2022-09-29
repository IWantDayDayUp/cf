#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(k);
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;

        a[i % k] = max(a[i % k], num);
    }

    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += a[i];
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