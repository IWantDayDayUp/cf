#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n & 1) {
        cout << "YES" << endl;
        int x = (3 * n + 3) / 2, y = x + n - 1;

        int k = y - 2 * n;
        while (k < y - k)
        {
            cout << k << ' ' << y - k << endl;
            k += 1;
            y -= 1;
        }

        k = 1;
        while (y >= x)
        {
            cout << k << ' ' << y - k << endl;
            k += 1;
            y -= 1;
        }
    } else {
        cout << "NO" << endl;
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