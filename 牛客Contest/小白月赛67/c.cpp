#include <bits/stdc++.h>

using namespace std;

void solve() {
    double b, x, y;
    cin >> b >> x >> y;
    double s = b * y / 2;
    s /= 2;

    for (int i = 0; i <= x; i++)
    {
        double cur = y * i / x;
        double cur_s = cur * i / 2;

        if (abs(cur_s - s) <= 1e-9)
        {
            cout << "YES" << endl;
            return ;
        }
    }

    for (int i = x; i <= b; i++)
    {
        double cur = y * (b - i) / (b - x);
        double cur_s = cur * (b - i) / 2;

        if (abs(cur_s - s) <= 1e-9)
        {
            cout << "YES" << endl;
            return ;
        }
    }

    cout << "NO" << endl;
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