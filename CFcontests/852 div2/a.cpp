#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, n, m;
    cin >> a >> b >> n >> m;

    long long x = n / (m + 1);
    long long y = n % (m + 1);

    long long ans = x * min(m * a, b * (m + 1)) + y * min(a, b);

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