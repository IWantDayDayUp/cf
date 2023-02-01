#include <bits/stdc++.h>

using namespace std;

void solve() {
    int w, d, h;
    cin >> w >> d >> h;
    int a, b, f, g;
    cin >> a >> b >> f >> g;

    int ans = 1e9;
    ans = min(min(w - a, a), min(w - f, f));
    ans = min(min(d - b, b), min(d - g, g));

    ans = ans * 2 + h + abs(a - f) + abs(b - g);

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