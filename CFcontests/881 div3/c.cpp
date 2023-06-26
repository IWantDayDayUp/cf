#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long ans = n;

    while (n)
    {
        n /= 2;
        ans += n;
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