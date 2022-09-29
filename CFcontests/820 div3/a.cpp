#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (abs(a - 1) == abs(b - c) + abs(c - 1))
    {
        cout << 3 << endl;
    } else if (abs(a - 1) < abs(b - c) + abs(c - 1))
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