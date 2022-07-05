#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    if (n < 4)
    {
        cout << -1 << endl;
    } else {
        for (int i = n; i >= 1; i--)
        {
            if (i & 1)
            {
                cout << i << ' ';
            }
        }
        cout << 4 << ' ' << 2 << ' ';
        for (int i = 6; i <= n; i+=2)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}