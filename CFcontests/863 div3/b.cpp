#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    n /= 2;

    auto calc = [&](int num)
    {
        if (num > n)
        {
            num = 1 + 2 * n - num;
        }

        return num;
    };

    x1 = calc(x1);
    y1 = calc(y1);
    x2 = calc(x2);
    y2 = calc(y2);
    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

    auto get = [&](int x, int y)
    {
        if (x >= y)
        {
            return n - y + 1;
        } else {
            return n - x + 1;
        }
    };

    int c1 = get(x1, y1), c2 = get(x2, y2);
    // cout << c1 << ' ' << c2 << endl;

    cout << abs(c1 - c2) << endl;
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