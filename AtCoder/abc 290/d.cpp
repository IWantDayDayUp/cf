#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    k--;

    int l = n / gcd(n, d);
    cout << (long long) d * (k % l) % n + k / l << endl;
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