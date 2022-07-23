#include <bits/stdc++.h>

using namespace std;

void slove() {
    int x;
    cin >> x;

    int a, b, c;
    cin >> a >> b >> c;

    if (x == 1)
    {
        if ((a == 2 && b == 3) || (a == 3 && c == 2))
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (x == 2)
    {
        if ((b == 1 && a == 3) || (b == 3 && c == 1))
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (x == 3)
    {
        if ((c == 1 && a == 2) || (c == 2 && b == 1))
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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