#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;

    long long mod = 998244353, ans = 0;

    int len = __lg(r / l) + 1;
    int cnt = (r >> (len - 1)) - l + 1;
    if (len >= 2)
    {
        cnt += max(0, ((r / 3) >> (len - 2)) - l + 1) * (len - 1);
    }

    cout << len << ' ' << cnt << endl;
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