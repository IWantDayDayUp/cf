#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int x = 0, y = 0;
    int m = 1, cnt = 0;
    while (n)
    {
        int t = n % 10;

        if (t & 1) {
            int t1 = t / 2 * m, t2 = (t + 1) / 2 * m;

            if (cnt & 1)
            {
                x += t1;
                y += t2;
            } else {
                x += t2;
                y += t1;
            }

            cnt += 1;
        } else {
            x += t * m / 2;
            y += t * m / 2;
        }

        n /= 10;
        m *= 10;
    }

    cout << x << ' ' << y << endl;
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