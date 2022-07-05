#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int x, y;
    cin >> x >> y;

    if (x > y)
    {
        cout << x + y << endl;
    } else {
        cout << y - (y % x) / 2 << endl;
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