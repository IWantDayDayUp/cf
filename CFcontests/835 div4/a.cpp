#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a - b) * (a - c) < 0)
    {
        cout << a << endl;
    } else if ((b - a) * (b - c) < 0)
    {
        cout << b << endl;
    } else {
        cout << c << endl;
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