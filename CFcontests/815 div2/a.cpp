#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * d == b * c)
    {
        cout << 0 << endl;
    } else if (a == 0 || c == 0)
    {
        cout << 1 << endl;
    } else if ((a * d) % (b * c) == 0 || (b * c) % (a * d) == 0)
    {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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