#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    x--;
    y--;

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (abs(i - x) + abs(0 - y) <= d)
        {
            ok = false;
            break;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (abs(n - 1 - x) + abs(j - y) <= d)
        {
            ok = false;
            break;
        }
    }

    if (ok)
    {
        cout << n - 1 + m - 1 << endl;
        return;
    }

    ok = true;
    for (int i = 0; i < n; i++)
    {
        if (abs(i - x) + abs(m - 1 - y) <= d)
        {
            ok = false;
            break;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (abs(0 - x) + abs(j - y) <= d)
        {
            ok = false;
            break;
        }
    }

    if (ok)
    {
        cout << n - 1 + m - 1 << endl;
    } else {
        cout << -1 << endl;
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